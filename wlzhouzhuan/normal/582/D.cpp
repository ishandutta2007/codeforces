#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define PB push_back
#define MP make_pair
#define PII pair<int,int>
#define FIR first
#define SEC second
#define ll long long
using namespace std;
template <class T>
inline void rd(T &x) {
	x=0; char c=getchar(); int f=1;
	while(!isdigit(c)) { if(c=='-') f=-1; c=getchar(); }
	while(isdigit(c)) x=x*10-'0'+c,c=getchar(); x*=f;
}
const int N=4010;
const int mod=1e9+7;
inline void Add(int &x,int y) { x+=y; if(x>=mod) x-=mod; }
int num[N],len;
int P,K;
char str[N];
int S[N],n;
inline int Sum(ll l,ll r) { return 1ll*(l+r)*(r-l+1)/2%mod; }
inline int calc(ll l,ll r) {
	l=max(l,0ll);
	if(l>r) return 0;
	ll tot=0;
	if(r>=P-1) tot+=(2*P-1)*(r-max(l,P-1ll)+1)-Sum(max(l,P-1ll),r),r=P-2;
	if(l<=r) tot+=Sum(l+1,r+1);
	return (tot%mod+mod)%mod;
}
int f[N][N][2][2];
int dp(int p,int tot,int s,int t) {
	if(p==-1) return !s&&tot>=K;
	if(~f[p][tot][s][t]) return f[p][tot][s][t];
	int res=0;
	if(t)
		if(!s) {
			Add(res,1ll*calc(0,P-2)*dp(p-1,tot+1,1,1)%mod);
			Add(res,1ll*calc(0,P-1)*dp(p-1,tot,0,1)%mod);
		}
		else {
			Add(res,1ll*calc(P-1,2*P-2)*dp(p-1,tot+1,1,1)%mod);
			Add(res,1ll*calc(P,2*P-1)*dp(p-1,tot,0,1)%mod);
		}
	else
		if(!s) {
			Add(res,1ll*calc(0,num[p]-1)*dp(p-1,tot,0,1)%mod);
			Add(res,1ll*calc(0,num[p]-2)*dp(p-1,tot+1,1,1)%mod);
			Add(res,1ll*calc(num[p],num[p])*dp(p-1,tot,0,0)%mod);
			Add(res,1ll*calc(num[p]-1,num[p]-1)*dp(p-1,tot+1,1,0)%mod);
		}
		else {
			Add(res,1ll*calc(P,P+num[p]-1)*dp(p-1,tot,0,1)%mod);
			Add(res,1ll*calc(P-1,P+num[p]-2)*dp(p-1,tot+1,1,1)%mod);
			Add(res,1ll*calc(P+num[p],P+num[p])*dp(p-1,tot,0,0)%mod);
			Add(res,1ll*calc(P+num[p]-1,P+num[p]-1)*dp(p-1,tot+1,1,0)%mod);
		}
	return f[p][tot][s][t]=res;
}
	
	
int main() {
  rd(P),rd(K);
	scanf("%s",str);
	n=strlen(str);
	for(int i=0;i<n;++i) S[i]=str[n-1-i]-'0';
	while(n) {
		ll cur=0;
		for(int i=n-1;i>=0;--i) cur=(cur*10+S[i])%P;
		num[len++]=cur;
		cur=0;
		for(int i=n-1;i>=0;--i) {
			cur=cur*10+S[i];
			S[i]=cur/P,cur%=P;
		}
		while(n&&S[n-1]==0) n--;
	}
	if(K>len) return printf("0"),0;
	memset(f,-1,sizeof(f));
	printf("%d",dp(len-1,0,0,0));
	return 0;
}