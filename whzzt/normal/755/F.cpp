#include"bits/stdc++.h"
using namespace std;
const int N=1000005,M=1005;
int n,k,a[N],fa[N],sz[N];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
int bl,b[N],mn,mx;
inline bool cmp(const int&x,const int&y){return x>y;}
int d[M*2],dt[M*2],dl,r[M*20],rl;
bitset<N> f[2];
bool ok(int x){
	x=min(x,n-x);
	for(int i=1;i<=bl;i++){
		if(b[i]==b[i-1])dt[dl]++;
		else d[++dl]=b[i],dt[dl]++;
	}
	for(int i=1;i<=dl;i++){
		int j=1;
		while(dt[i]>j){
			r[++rl]=j*d[i];
			dt[i]-=j;j=j*2;
		}
		r[++rl]=dt[i]*d[i];
	}
	f[0]=1;
	for(int i=1;i<=rl;i++)
		f[i&1]=f[(i-1)&1]|(f[(i-1)&1]<<r[i]);
	return f[rl&1][x]==1;
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)fa[i]=i,sz[i]=1;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		int fx=find(a[i]),fi=find(i);
		if(fx!=fi)fa[fx]=fi,sz[fi]+=sz[fx];
	}
	for(int i=1;i<=n;i++)if(fa[i]==i)b[++bl]=sz[i];
	sort(b+1,b+n+1,cmp);int rem=k,f1=0,f2=0;
	for(int i=1;i<=bl;i++)f2+=b[i]/2,f1+=b[i]&1;
	if(f2>=k)mx=k*2;else if(f1+f2>=k)mx=f2*2+k-f2;else mx=f2*2+f1;mn=k+1;
	if(ok(k))mn=k;printf("%d %d\n",mn,mx);
	return 0;
}