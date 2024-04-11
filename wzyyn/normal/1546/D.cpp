#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
using namespace std;

const int N=1000005;
const int mo=998244353;
int fac[N],inv[N];
void init(){
	fac[0]=inv[0]=inv[1]=1;
	for (int i=2;i<N;i++)
		inv[i]=1ll*inv[mo%i]*(mo-mo/i)%mo;
	for (int i=1;i<N;i++)
		inv[i]=1ll*inv[i-1]*inv[i]%mo;
	for (int i=1;i<N;i++)
		fac[i]=1ll*fac[i-1]*i%mo;
}
char s[N];
int n;
void solve(){
	scanf("%d%s",&n,s+1);
	int s0=0,s1=0,fl=0;
	for (int i=1;i<=n;i++)
		if (s[i]=='0') ++s0,fl=0;
		else if (!fl) fl=1;
		else ++s1,fl=0;
	printf("%d\n",1ll*fac[s0+s1]*inv[s0]%mo*inv[s1]%mo);
}
int main(){
	
	init();
	int T;
	scanf("%d",&T);
	while (T--) solve();
	
}