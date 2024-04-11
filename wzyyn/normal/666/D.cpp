#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
using namespace std;
struct P{
	int x,y,id;
};
P a[10],p[10],Ans[10],tmp[10];
P q1[10],q2[10],x[10],y[10];
int ans,rev,vis1[10],vis2[10];
void findans(int k,int sz1,int sz2,int v){
	if (v>=ans) return;
	if (k==5){
		ans=v;
		For(i,1,4){
			Ans[i]=tmp[i];
			if (rev) swap(Ans[i].x,Ans[i].y);
		}
		return;
	}
	For(i,1,sz1)
		if (p[k].x==x[i].x&&!vis1[i]){
			vis1[i]=1;
			tmp[x[i].id]=p[k];
			findans(k+1,sz1,sz2,max(v,abs(p[k].y-x[i].y)));
			vis1[i]=0;
		}
	For(i,1,sz2)
		if (p[k].y==y[i].y&&!vis2[i]){
			vis2[i]=1;
			tmp[y[i].id]=p[k];
			findans(k+1,sz1,sz2,max(v,abs(p[k].x-y[i].x)));
			vis2[i]=0;
		}
}
void work04(){
	For(i,1,4) For(j,i+1,4)
		if (x[i].x>x[j].x) swap(x[i],x[j]);
	if (x[1].x!=x[2].x||x[2].x==x[3].x||x[3].x!=x[4].x) return;
	int d=x[3].x-x[2].x;
	if (x[1].y<x[2].y) swap(x[1],x[2]);
	if (x[3].y<x[4].y) swap(x[3],x[4]);
	x[2].y+=d; x[4].y+=d;
	int id1=x[1].id,id3=x[3].id;
	For(i,1,4) For(j,i+1,4)
		if (x[i].y>x[j].y) swap(x[i],x[j]);
	int val=(x[4].y-x[1].y+1)/2;
	int pos=x[4].y-val;
	if (val<ans){
		ans=val;
		For(i,1,4){
			Ans[x[i].id].x=x[i].x;
			Ans[x[i].id].y=pos-(x[i].id==id1||x[i].id==id3?0:d);
		}
		if (rev)
			For(i,1,4)
				swap(Ans[i].x,Ans[i].y);
	}
}
void work13(){
	if (x[1].x!=x[2].x&&x[2].x!=x[3].x&&x[1].x!=x[3].x) return;
	if (x[1].x==x[3].x) swap(x[2],x[3]);
	if (x[2].x==x[3].x) swap(x[1],x[3]);
	int d=abs(x[1].x-x[3].x);
	if (!d) return;
	p[1].x=p[2].x=x[1].x;
	p[3].x=p[4].x=x[3].x;
	p[1].y=p[3].y=y[1].y;
	p[2].y=p[4].y=y[1].y-d;
	findans(1,3,1,0);
	p[2].y=p[4].y=y[1].y+d;
	findans(1,3,1,0);
}
void work22(){
	int dx=abs(x[1].x-x[2].x);
	int dy=abs(y[1].y-y[2].y);
	if (!dx&&!dy) return;
	p[1].x=p[2].x=x[1].x;
	p[3].x=p[4].x=x[2].x;
	p[1].y=p[3].y=y[1].y;
	p[2].y=p[4].y=y[2].y;
	if (dx==dy) findans(1,2,2,0);
	if (!dx&&dy){
		p[1].x=p[2].x=x[1].x-dy;
		findans(1,2,2,0);
		p[1].x=p[2].x=x[1].x+dy;
		findans(1,2,2,0);
		p[1].x=p[2].x=x[1].x;
	}
	if (!dy&&dx){
		p[1].y=p[3].y=y[1].y-dx;
		findans(1,2,2,0);
		p[1].y=p[3].y=y[1].y+dx;
		findans(1,2,2,0);
		p[1].y=p[3].y=y[1].y;
	}
}
void dfs(int k,int sz1,int sz2){
	if (k==5){
		memcpy(x,q1,sizeof(x));
		memcpy(y,q2,sizeof(y));
		if (rev=(sz1<sz2)){
			swap(sz1,sz2);
			For(i,1,sz1) swap(x[i],y[i]);
			For(i,1,sz1) swap(x[i].x,x[i].y);
			For(i,1,sz1) swap(y[i].x,y[i].y);
		}
		if (sz2==0) work04();
		if (sz2==1) work13();
		if (sz2==2) work22();
		return;
	}
	q1[sz1+1]=a[k];
	dfs(k+1,sz1+1,sz2);
	q2[sz2+1]=a[k];
	dfs(k+1,sz1,sz2+1);
}
void solve(){
	ans=1<<30;
	For(i,1,4){
		scanf("%d%d",&a[i].x,&a[i].y);
		a[i].id=i;
	}
	dfs(1,0,0);
	if (ans==(1<<30)) puts("-1");
	else{
		printf("%d\n",ans);
		For(i,1,4)
			printf("%d %d\n",Ans[i].x,Ans[i].y);
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}