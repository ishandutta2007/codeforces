/*
Contest: Educational Codeforces Round 90
Problem: Codeforces 1373C
Author: tzc_wk
Time: 2020.6.25
*/
#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define all(a)		a.begin(),a.end()
#define giveup(...) return printf(__VA_ARGS__),0;
#define fill0(a)	memset(a,0,sizeof(a))
#define fill1(a)	memset(a,-1,sizeof(a))
#define fillbig(a)	memset(a,0x3f,sizeof(a))
#define fillsmall(a) memset(a,0xcf,sizeof(a))
#define mask(a)		(1ll<<(a))
#define maskx(a,x)	((a)<<(x))
#define _bit(a,x)	(((a)>>(x))&1)
#define _sz(a)		((int)(a).size())
#define filei(a)	freopen(a,"r",stdin);
#define fileo(a)	freopen(a,"w",stdout);
#define fileio(a) 	freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#define put(x)		putchar(x)
#define eoln        put('\n')
#define space		put(' ')
#define y1			y1010101010101
#define y0			y0101010101010
#define int long long
typedef pair<int,int> pii;
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-')	neg=-1;
		c=getchar();
	}
	while(isdigit(c))	x=x*10+c-'0',c=getchar();
	return x*neg;
}
inline int qpow(int x,int e,int _MOD){
	int ans=1;
	while(e){
		if(e&1)	ans=ans*x%_MOD;
		x=x*x%_MOD;
		e>>=1;
	}
	return ans;
}
char s[1000005];
int sum[1000005];
signed main(){
	int T=read();
	while(T--){
		cin>>s+1;
		map<int,int> cnt;
		int n=strlen(s+1);
		int cur=0;
		fz(i,1,n){
			if(s[i]=='+')	sum[i]=sum[i-1]+1;
			else			sum[i]=sum[i-1]-1;
		}
		fz(i,1,n)	sum[i]=min(sum[i],sum[i-1]);
		fz(i,1,n)	sum[i]=-sum[i];
		int ans=0;
		sum[n+1]=0x3f3f3f3f;
		fd(i,n,0)	if(sum[i]!=sum[i+1])	ans+=i+1;
		cout<<ans-1<<endl;
	}
	return 0;
}