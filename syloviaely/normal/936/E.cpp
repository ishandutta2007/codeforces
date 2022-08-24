#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <cassert>
using namespace std;
const int N=310000,M=300000;
struct point{
	int x,y;
}x[N];
int p[N],L[N],R[N],n,q;
struct bian{
	int next,point;
}b[N*2];
int pd[N],size[N],m,len,root[N];
const int gox[4]={1,0,-1,0},goy[4]={0,1,0,-1};
map<pair<int,int>,int>loc,B;
int compare(point k1,point k2){
	return k1.x<k2.x||(k1.x==k2.x&&k1.y<k2.y);
}
void ade(int k1,int k2){
	b[++len]=(bian){p[k1],k2}; p[k1]=len;
}
void add(int k1,int k2){
	//cout<<"add "<<k1<<" "<<k2<<endl;
	ade(k1,k2); ade(k2,k1);
}
void addin(int k1,int k2){
	if (k1>k2) swap(k1,k2); if (k1==k2) return;
	if (B[make_pair(k1,k2)]) return;
	add(k1,k2); B[make_pair(k1,k2)]=1;
}
struct atom{
	int l,r,w,finloc;
}A[19][N];
int father[N],now,where,D[N];
int dfs1(int k1,int k2){
	size[k1]=1;
	for (int i=p[k1];i;i=b[i].next){
		int j=b[i].point;
		if (j!=k2&&pd[j]==0) size[k1]+=dfs1(j,k1);
	}
	return size[k1];
}
void dfs2(int k1,int k2){
	int num=n-size[k1];
	for (int i=p[k1];i;i=b[i].next){
		int j=b[i].point;
		if (j!=k2&&pd[j]==0){
			dfs2(j,k1); num=max(num,size[j]);
		}
	}
	if (num<now){
		now=num; where=k1;
	}
}
void dfs3(int k1,int k2,int d){
	int l=max(A[d][k2].l,L[k1]),r=min(A[d][k2].r,R[k1]);
	if (l<=r) A[d][k1]=(atom){l,r,A[d][k2].w+1,A[d][k2].finloc};
	else if (L[k1]>A[d][k2].r){
		A[d][k1]=(atom){L[k1],L[k1],A[d][k2].w+L[k1]-A[d][k2].r+1,A[d][k2].finloc};
		if (A[d][k1].finloc==-1) A[d][k1].finloc=A[d][k2].r;
	} else {
		A[d][k1]=(atom){R[k1],R[k1],A[d][k2].w+A[d][k2].l-R[k1]+1,A[d][k2].finloc};
		if (A[d][k1].finloc==-1) A[d][k1].finloc=A[d][k2].l;
	}
	//cout<<k1<<" "<<k2<<" "<<A[d][k1].l<<" "<<A[d][k1].r<<" "<<A[d][k1].w<<endl;
	for (int i=p[k1];i;i=b[i].next){
		int j=b[i].point;
		if (j!=k2&&pd[j]==0) dfs3(j,k1,d);
	}
}
void dowith(int k1,int fa=0,int d=0){
	n=dfs1(k1,0); now=n; where=0; dfs2(k1,0); int k=where; pd[k]=1; father[k]=fa; D[k]=d;
	assert(d<=18);
	A[d][k]=(atom){L[k],R[k],0,-1}; root[k]=0;// cout<<"dowith "<<k<<" "<<fa<<" "<<d<<endl;
	for (int i=p[k];i;i=b[i].next){
		int j=b[i].point;
		if (pd[j]==0) dfs3(j,k,d);
	}
	for (int i=p[k];i;i=b[i].next){
		int j=b[i].point;
		if (pd[j]==0) dowith(j,k,d+1);
	}
}
struct tree{
	int l,r,w1,w2;
}t[1500000];
int query1(int k1,int k2,int k3,int k4,int k5){
	if (k2>k5||k3<k4||k1==0) return 1e9;
	if (k2>=k4&&k3<=k5) return t[k1].w1;
	int mid=k2+k3>>1;
	return min(query1(t[k1].l,k2,mid,k4,k5),query1(t[k1].r,mid+1,k3,k4,k5));
}
int query2(int k1,int k2,int k3,int k4,int k5){
	if (k2>k5||k3<k4||k1==0) return 1e9;
	if (k2>=k4&&k3<=k5) return t[k1].w2;
	int mid=k2+k3>>1;
	return min(query2(t[k1].l,k2,mid,k4,k5),query2(t[k1].r,mid+1,k3,k4,k5));
}
int change(int k1,int k2,int k3,int k4,int k5,int k6){
	if (k1==0){
		k1=++len; t[k1].w1=1e9; t[k1].w2=1e9;
	}
	assert(len<=5590000);
	t[k1].w1=min(t[k1].w1,k5); t[k1].w2=min(t[k1].w2,k6);
	if (k2==k3) return k1; int mid=k2+k3>>1;
	if (mid>=k4) t[k1].l=change(t[k1].l,k2,mid,k4,k5,k6);
	else t[k1].r=change(t[k1].r,mid+1,k3,k4,k5,k6);
	return k1;
}
int query(int k1,int k2){
	int ans=1e9;
	for (int now=k1;now;now=father[now]){
		int d=D[now];
		int where=k2,curdis=A[d][k1].w;
		if (where>A[d][k1].r){
			curdis+=k2-A[d][k1].r; where=A[d][k1].r;
		} else if (where<A[d][k1].l){
			curdis+=A[d][k1].l-k2; where=A[d][k1].l;
		}
		if (A[d][k1].finloc!=-1) where=A[d][k1].finloc;
		int num=min(query1(root[now],L[now],R[now],L[now],where)+where,query2(root[now],L[now],R[now],where,R[now])-where);
		//cout<<"query "<<now<<" "<<k1<<" "<<curdis<<" "<<num<<" "<<where<<" "<<query1(root[now],L[now],R[now],L[now],where)<<" "<<query2(root[now],L[now],R[now],where,R[now])<<endl;
		ans=min(ans,num+curdis);
	}
	return ans;
}
void insert(int k1,int k2){
	for (int now=k1;now;now=father[now]){
		int d=D[now];
		int where=k2,curdis=A[d][k1].w;
		if (where>A[d][k1].r){
			curdis+=k2-A[d][k1].r; where=A[d][k1].r;
		} else if (where<A[d][k1].l){
			curdis+=A[d][k1].l-k2; where=A[d][k1].l;
		}
		if (A[d][k1].finloc!=-1) where=A[d][k1].finloc;
	//	cout<<"insert "<<now<<" "<<where<<" "<<curdis-where<<" "<<curdis+where<<" "<<endl;
		root[now]=change(root[now],L[now],R[now],where,curdis-where,curdis+where);
	}
}
int flag=0;
int check(){
	int mi=1e9,ma=0,dis=0;
	for (int i=1;i<=n;i++) mi=min(mi,x[i].x),ma=max(ma,x[i].x);
	dis=ma-mi;
	mi=1e9; ma=0;
	for (int i=1;i<=n;i++) mi=min(mi,x[i].y),ma=max(ma,x[i].y);
	if (ma-mi<dis) return 1; return 0;
}
int main(){
	scanf("%d",&m);
	for (int i=1;i<=m;i++) scanf("%d%d",&x[i].x,&x[i].y);
	if (check()){
		flag=1;
		for (int i=1;i<=m;i++) swap(x[i].x,x[i].y);
	}
	sort(x+1,x+m+1,compare);
	n=0; int pre=1;
	for (int i=2;i<=m+1;i++)
		if (i>m||x[i].x!=x[i-1].x||x[i].y!=x[i-1].y+1){
			n++; L[n]=x[pre].y; R[n]=x[i-1].y;
			for (int j=pre;j<i;j++) loc[make_pair(x[j].x,x[j].y)]=n;
			pre=i;
		}
	//cout<<"point"<<endl;
	//for (int i=1;i<=n;i++) cout<<L[i]<<" "<<R[i]<<endl;
	for (int i=1;i<=m;i++)
		for (int j=0;j<4;j++){
			int k1=x[i].x+gox[j],k2=x[i].y+goy[j];
			if (loc[make_pair(k1,k2)]) addin(loc[make_pair(x[i].x,x[i].y)],loc[make_pair(k1,k2)]);
		}
	dowith(1); len=0; scanf("%d",&q);
	for (;q;q--){
		int k1; scanf("%d",&k1);
		if (k1==1){
			int k2,k3; scanf("%d%d",&k2,&k3);
			if (flag) swap(k2,k3);
			insert(loc[make_pair(k2,k3)],k3);
		} else if (k1==2){
			int k2,k3; scanf("%d%d",&k2,&k3);
			if (flag) swap(k2,k3);
			int ans=query(loc[make_pair(k2,k3)],k3);
			if (ans>1e8) ans=-1;
			printf("%d\n",ans);
		}
	}
	return 0;
}