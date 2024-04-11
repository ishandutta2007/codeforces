#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int N=100005;
const int M=205,B=500;
int n,Q,be[N],cnt;
int L[M],R[M],a[N],fa[N];
int S[M][N],st[M][N];
int tg[M],mx[M];
void merge(int x,int y,int z){
	if (S[x][y]){
		S[x][z]+=S[x][y]; S[x][y]=0;
		fa[st[x][y]]=st[x][z];
		a[st[x][y]]=z;
		if (!st[x][z]) st[x][z]=st[x][y];
		st[x][y]=0;
	}
}
void change(int x,int v){
	if (mx[x]<v) return;
	if (mx[x]>=2*v){
		For(i,1,v){
			++tg[x];
			merge(x,tg[x],tg[x]+v);
		}
		mx[x]-=v;
	}
	else
		for (;mx[x]>v;--mx[x])
			merge(x,tg[x]+mx[x],tg[x]+mx[x]-v);
}
void pushdown(int x){
	static int q[M];
	For(i,L[x],R[x]) a[i]=(st[x][a[i]]==i?a[i]:-1);
	For(i,L[x],R[x]) if (a[i]==-1){
		*q=0;
		for (int j=i;;j=fa[j]){
			q[++*q]=j;
			if (a[j]!=-1) break;
		}
		For(j,1,(*q)-1)
			a[q[j]]=a[q[*q]];
	}
	For(i,L[x],R[x]) st[x][a[i]]=S[x][a[i]]=0;
	For(i,L[x],R[x]) a[i]-=tg[x],fa[i]=0;
	tg[x]=0;
}
void build(int x){
	mx[x]=0;
	For(i,L[x],R[x]) ++S[x][a[i]];
	For(i,L[x],R[x]){
		mx[x]=max(mx[x],a[i]);
		fa[i]=st[x][a[i]];
		if (!fa[i]) st[x][a[i]]=i;
	}
}
int query(int x,int v){
	return v+tg[x]>=N?0:S[x][v+tg[x]];
}
void solve(int be,int tp,int l,int r,int v,int &ans){
	if (l==-1) l=L[be];
	if (r==-1) r=R[be];
	pushdown(be);
	if (tp==1) For(i,l,r) (a[i]>v?a[i]-=v:233); 
	else For(i,l,r) ans+=(a[i]==v);
	build(be);
}
int main(){
	//freopen("1.in","r",stdin);
	scanf("%d%d",&n,&Q);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) be[i]=(i-1)/B+1;
	cnt=be[n];
	For(i,1,cnt){
		L[i]=(i-1)*B+1;
		R[i]=min(i*B,n);
		build(i);
	}
	//cerr<<233<<endl;
	while (Q--){
		int tp,x,y,v,ans=0;
		scanf("%d%d%d%d",&tp,&x,&y,&v);
		int bx=(x-1)/B+1,by=(y-1)/B+1;
		//cerr<<Q<<' '<<tp<<' '<<bx<<' '<<by<<endl;
		if (bx==by) solve(bx,tp,x,y,v,ans);
		else{
			solve(bx,tp,x,-1,v,ans);
			solve(by,tp,-1,y,v,ans);
			For(i,bx+1,by-1)
				tp==1?(change(i,v),0):ans+=query(i,v);
		}
		if (tp==2)
			printf("%d\n",ans);
	}
}
/*
:
2x<=mx     [0,x-1]
 x<=mx<2x  [x,mx]
    mx<x    

:
 
getfa 
*/