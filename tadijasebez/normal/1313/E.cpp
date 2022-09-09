#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
#define mt make_tuple
#define ldb double
#define pii pair<int,int>
#define pll pair<ll,ll>
template<typename T>void ckmn(T &a,T b){a=min(a,b);}
template<typename T>void ckmx(T &a,T b){a=max(a,b);}
int ri(){int x;scanf("%i",&x);return x;}
void rd(){}
template<typename...T>void rd(int &x,T&...args){scanf("%i",&x);rd(args...);}
template<typename...T>void rd(ll &x,T&...args){scanf("%lld",&x);rd(args...);}
template<typename...T>void rd(ldb &x,T&...args){scanf("%lf",&x);rd(args...);}
template<typename...T>void rd(pii &x,T&...args){scanf("%i %i",&x.first,&x.second);rd(args...);}
const int N=1000050;
char a[N],b[N],s[N];
int go[N],A[N],B[N];
void Z(char a[],char s[],int lcp[]){
	int m=strlen(s+1),n=strlen(a+1);
	int L=0,R=0;
	for(int i=2;i<=m;i++){
		if(i<=R)go[i]=min(go[i-L+1],R-i+1);
		else go[i]=0;
		while(i+go[i]<=m&&s[go[i]+1]==s[i+go[i]])go[i]++;
		if(i+go[i]-1>R)L=i,R=go[i]+i-1;
	}
	L=R=0;
	for(int i=1;i<=n;i++){
		if(i<=R)lcp[i]=min(go[i-L+1],R-i+1);
		while(i+lcp[i]<=n&&lcp[i]+1<=m&&s[lcp[i]+1]==a[i+lcp[i]])lcp[i]++;
		if(i+lcp[i]-1>R)L=i,R=lcp[i]+i-1;
	}
}
pll operator+(pll a,pll b){return mp(a.first+b.first,a.second+b.second);}
pll operator-(pll a,pll b){return mp(a.first-b.first,a.second-b.second);}
pll operator+=(pll&a,pll b){return a=a+b;}
pll sum[N];
void Add(int i,pll f){for(i++;i<N;i+=i&-i)sum[i]+=f;}
pll Get(int i){pll ans={0,0};for(i++;i;i-=i&-i)ans+=sum[i];return ans;}
int main(){
	int n,m;rd(n,m);
	scanf("%s %s %s",a+1,b+1,s+1);
	Z(a,s,A);
	reverse(b+1,b+1+n);
	reverse(s+1,s+1+m);
	Z(b,s,B);
	reverse(B+1,B+1+n);
	for(int i=1;i<=n;i++)if(A[i]==m)A[i]=m-1;
	for(int i=1;i<=n;i++)if(B[i]==m)B[i]=m-1;
	ll ans=0;
	for(int i=1,ptr=1;i<=n;i++){
		while(ptr<=n&&ptr<i+m-1)Add(B[ptr],{1,B[ptr]}),ptr++;
		pll now=Get(N-2)-Get(m-A[i]-1);
		ans+=now.second-(m-A[i]-1)*now.first;
		Add(B[i],{-1,-B[i]});
	}
	printf("%lld\n",ans);
	return 0;
}