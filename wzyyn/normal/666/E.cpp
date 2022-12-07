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
const int N=1000005;
const int M=10000005;
int ch[N][26],l[N],fa[N];
int nd=1,las,faa[N][22];
void extend(int c){
	int p=las,np=++nd;
	l[np]=l[p]+1;
	for (;p&&!ch[p][c];p=fa[p]) ch[p][c]=np;
	if (!p) fa[np]=1;
	else{
		int q=ch[p][c];
		if (l[q]==l[p]+1) fa[np]=q;
		else{
			int nq=++nd; l[nq]=l[p]+1;
			memcpy(ch[nq],ch[q],sizeof(ch[q]));
			fa[nq]=fa[q]; fa[q]=fa[np]=nq;
			for (;p&&ch[p][c]==q;p=fa[p]) ch[p][c]=nq;
		}
	}
	las=np;
}
struct query{
	int x,y,l,r,pos,val;
}q[N];
int n,m,Q,ndd;
int rt[N];
char s[N],t[N];
int ls[M],rs[M];
pii v[M];
vector<int> vec[N];
vector<int> vecQ[N];
vector<int> e[N];
void insert(int &k,int l,int r,int p){
	if (!k) k=++nd;
	if (l==r){
		v[k].fi++;
		v[k].se=-l;
		return;
	}
	int mid=(l+r)/2;
	if (p<=mid) insert(ls[k],l,mid,p);
	else insert(rs[k],mid+1,r,p);
	v[k]=max(v[ls[k]],v[rs[k]]);
}
int merge(int x,int y,int l,int r){
	if (!x||!y) return x+y;
	if (l==r){
		v[x].fi+=v[y].fi;
		return x;
	}
	int mid=(l+r)/2;
	ls[x]=merge(ls[x],ls[y],l,mid);
	rs[x]=merge(rs[x],rs[y],mid+1,r);
	v[x]=max(v[ls[x]],v[rs[x]]);
	return x;
}
pii ask(int k,int l,int r,int x,int y){
	if (!k) return pii(0,0);
	if (l==x&&r==y) return v[k];
	int mid=(l+r)/2;
	if (y<=mid) return ask(ls[k],l,mid,x,y);
	if (x>mid) return ask(rs[k],mid+1,r,x,y);
	return max(ask(ls[k],l,mid,x,mid),ask(rs[k],mid+1,r,mid+1,y));
}
void getans(int x){
	For(i,0,e[x].size()-1){
		getans(e[x][i]);
		rt[x]=merge(rt[x],rt[e[x][i]],1,m);
	}
	For(i,0,vecQ[x].size()-1){
		int id=vecQ[x][i];
		pii tmp=ask(rt[x],1,m,q[id].l,q[id].r);
		q[id].pos=-tmp.se; q[id].val=tmp.fi;
	}
}
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	scanf("%d",&m);
	For(i,1,m){
		las=1;
		scanf("%s",t+1);
		int len=strlen(t+1);
		For(j,1,len){
			extend(t[j]-'a');
			insert(rt[las],1,m,i);
		}
	}
	scanf("%d",&Q);
	For(i,1,Q){
		scanf("%d%d",&q[i].l,&q[i].r);
		scanf("%d%d",&q[i].x,&q[i].y);
		vec[q[i].y].PB(i);
	}
	For(i,2,nd) e[fa[i]].PB(i);
	For(i,1,nd) faa[i][0]=fa[i];
	For(i,1,20) For(j,1,nd)
		faa[j][i]=faa[faa[j][i-1]][i-1];
	int x=1,len=0;
	For(i,1,n){
		int c=s[i]-'a';
		for (;x&&!ch[x][c];x=fa[x],len=l[x]);
		if (!x) x=1,len=0;
		else{
			x=ch[x][c]; ++len;
			For(j,0,vec[i].size()-1){
				int id=vec[i][j];
				int Qlen=q[id].y-q[id].x+1;
				if (Qlen>len) continue;
				int tmp=x;
				Rep(i,20,0)
					if (l[faa[tmp][i]]>=Qlen)
						tmp=faa[tmp][i];
				//printf("%d %d %d %d\n",id,tmp,x,l[faa[tmp][0]]);
				vecQ[tmp].PB(id);
			}
		}
	}
	getans(1);
	For(i,1,Q){
		if (!q[i].pos) q[i].pos=q[i].l;
		printf("%d %d\n",q[i].pos,q[i].val);
	}
}