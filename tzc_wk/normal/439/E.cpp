/*
Contest: -
Problem: Codeforces 439E
Author: tzc_wk
Time: 2020.9.21
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
#define int long long
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
const int MOD=1e9+7;
int f[100005],ff[100005];
inline int qpow(int x,int e){
	int ans=1;
	while(e){
		if(e&1) ans=ans*x%MOD;
		x=x*x%MOD;e>>=1;
	} return ans;
}
bool vis[100005];
int pr[100005],pcnt=0,mu[100005];
inline void init(int n){
	f[0]=1;for(int i=1;i<=n;i++) f[i]=f[i-1]*i%MOD;
	ff[n]=qpow(f[n],MOD-2);
	for(int i=n;i>=1;i--) ff[i-1]=ff[i]*i%MOD;
	mu[1]=1;
	for(int i=2;i<=n;i++){
		if(!vis[i]){pr[++pcnt]=i;mu[i]=-1;}
		for(int j=1;j<=pcnt&&pr[j]*i<=n;j++){
			vis[pr[j]*i]=1;
			if(i%pr[j]==0) break;
			else mu[i*pr[j]]=-mu[i];
		}
	}
}
inline int calc(int x,int y){
	if(x<0||y<0||x-y<0) return 0;
	return f[x]*ff[y]%MOD*ff[x-y]%MOD;
}
int T=read(),ans=0;
signed main(){
	init(100000);
	while(T--){
		int n=read(),k=read(),ans=0;
		if(k==1){printf("%d\n",(n==1));continue;}
		for(int i=1;i*i<=n;i++){
			if(n%i) continue;
			ans=(ans+mu[i]*calc(n/i-1,k-1)%MOD+MOD)%MOD;
			if(n/i!=i) ans=(ans+mu[n/i]*calc(i-1,k-1)%MOD+MOD)%MOD;
		} printf("%lld\n",ans);
	}
	return 0;
}