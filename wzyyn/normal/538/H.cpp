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
const int N=100005;
int L,R,n,m;
int l[N],r[N],vv[N];
int fa[N],v[N],fav[N];
int get(int x){
	if (x==fa[x]) return x;
	int tmp=get(fa[x]);
	v[x]=v[fa[x]]^fav[x];
	fav[x]=v[x]^v[tmp];
	return fa[x]=tmp;
}
void GG(){
	puts("IMPOSSIBLE");
	exit(0);
}
void merge(int x,int y){
	int xx=get(x),yy=get(y);
	if (xx!=yy) fa[xx]=yy,fav[xx]=v[x]^v[y]^1;
	else if (v[x]^v[y]^1) GG();
}
void sett(int x,int y){
	int xx=get(x);
	if (vv[xx]==-1) vv[xx]=y^v[x];
	else if (vv[xx]^y^v[x]) GG();
}
int main(){
	scanf("%d%d%d%d",&L,&R,&n,&m);
	int n1=0,n2=1<<30;
	For(i,1,n){
		scanf("%d%d",&l[i],&r[i]);
		n1=max(n1,l[i]);
		n2=min(n2,r[i]);
	}
	if (n1+n2<L) n1+=L-n1-n2;
	if (n1+n2>R) n2-=n1+n2-R;
	if (n1<0||n2<0) GG();
	For(i,1,n) fa[i]=i,vv[i]=-1;
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		merge(x,y);
	}
	For(i,1,n){
		if (n1<l[i]||n1>r[i]) sett(i,1);
		if (n2<l[i]||n2>r[i]) sett(i,0);
	}
	For(i,1,n)
		if (vv[i]==-1)
			vv[i]=0;
	printf("POSSIBLE\n%d %d\n",n1,n2);
	For(i,1,n) get(i),putchar(v[i]^vv[fa[i]]?'2':'1');
}