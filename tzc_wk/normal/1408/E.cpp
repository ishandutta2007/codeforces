/*
Contest: Grakn Forces 2020
Problem: Codeforces 1408E
Author: tzc_wk
Time: 2020.9.30
*/
#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define pb			push_back
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define all(a)		a.begin(),a.end()
#define fill0(a)	memset(a,0,sizeof(a))
#define fill1(a)	memset(a,-1,sizeof(a))
#define fillbig(a)	memset(a,0x3f,sizeof(a))
#define y1			y1010101010101
#define y0			y0101010101010
typedef pair<int,int> pii;
typedef long long ll;
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-') neg=-1;
		c=getchar();
	}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	return x*neg;
}
int n=read(),m=read(),a[100005],b[100005];ll ans=0,sum=0;
struct edge{
	int u,v;ll w;
	friend bool operator <(edge a,edge b){
		return a.w>b.w;
	}
} e[200005];
int ecnt=0,f[200005];
inline int find(int x){
	return (f[x]==x)?x:(f[x]=find(f[x]));
}
int main(){
	fz(i,1,n) a[i]=read();
	fz(i,1,m) b[i]=read();
	fz(i,1,n+m) f[i]=i;
	for(int i=1;i<=n;i++){
		int len=read();
		while(len--){
			int x=read();
			e[++ecnt]={i+m,x,a[i]+b[x]};
			ans+=a[i]+b[x];
		}
	}
	sort(e+1,e+ecnt+1);
	for(int i=1;i<=ecnt;i++){
		int u=e[i].u,v=e[i].v;
		int fu=find(u),fv=find(v);
		if(fu!=fv){
			f[fu]=fv;sum+=e[i].w;
		}
	}
	printf("%lld\n",ans-sum);
	return 0;
}