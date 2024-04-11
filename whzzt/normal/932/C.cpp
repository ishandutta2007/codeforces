#include<bits/stdc++.h>

#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-funroll-loops")
#pragma GCC target("avx,sse4")

#define mms(a,n) memset(a,0,sizeof((a)[0])*(n))
#define mmp(a,b,n) memcpy(a,b,sizeof((b)[0])*(n))
#define lowbit(x) ((x)&-(x))
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define fo(i,l,r) for(register int i=l,_lim_=r;i<=_lim_;i++)
#define fd(i,r,l) for(register int i=r,_lim_=l;i>=_lim_;i--)
#define fos(i,l,r,d) for(register int i=l,_lim_=r;i<=r;i+=d)
#define fol(i,l,r) for(register ll i=l,_lim_=r;i<=_lim_;i++)
#define fdl(i,r,l) for(register ll i=r,_lim_=l;i>=_lim_;i--)
#define fosl(i,l,r,d) for(register ll i=l,_lim_=r;i<=r;i+=d)
#define Clear(a) memset(a,0,sizeof(a))
#define Copy(a,b) memcpy(a,b,sizeof(b))
#define ALL(v) v.begin(),v.end()
#define SZ(v) ((int)v.size())

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ldb;
typedef double db;
typedef pair<int,int> pi;

const int N=1000005;
int n,a,b,p[N];ll x,y;
void exgcd(int a,int b,ll&x,ll&y){
	if(!b)return (void)(x=1,y=0);
	exgcd(b,a%b,y,x);y-=a/b*x;
}
void make(int l,int r){
	fo(i,l,r-1)p[i]=i+1;
	p[r]=l;
}

int main(){
	scanf("%d%d%d",&n,&a,&b);
	int g=__gcd(a,b);
	if(n%g)puts("-1"),exit(0);
	exgcd(a,b,x,y);
	while(x<0)x+=b/g,y-=a/g;
	while(x>=b/g)x-=b/g,y+=a/g;
	x*=n/g;y*=n/g;
	while(x<0)x+=b/g,y-=a/g;
	while(x>=b/g)x-=b/g,y+=a/g;
	if(x<0||y<0)puts("-1"),exit(0);
	fo(i,1,x)make((i-1)*a+1,i*a);
	fo(i,1,y)make(a*x+(i-1)*b+1,a*x+i*b);
	fo(i,1,n)printf("%d ",p[i]);
	return 0;
}