#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int mod=998244353;
const int maxn=(2e5)+10;
int n,m,cnt,ans;
char s[maxn];
int x,ivjc[maxn],jc[maxn],iv[maxn];
int C(int x,int y) {
	if (x<y||y<0) return 0;
	return (ll)jc[x]*ivjc[y]%mod*ivjc[x-y]%mod;
}
void update(int &x,int y) {
	x+=y; if (x>=mod) x-=mod;
}
int ksm(int x,int y) {
	int res=1;
	while (y) {
		if (y&1) res=(ll)res*x%mod;
		x=(ll)x*x%mod; y>>=1;
	} return res;
}
int main() {
	//freopen("1.txt","r",stdin);
	iv[0]=ivjc[0]=jc[0]=iv[1]=ivjc[1]=jc[1]=1;
	for (int i=2;i<maxn;i++) {
		jc[i]=(ll)jc[i-1]*i%mod;
		iv[i]=(ll)(mod-mod/i)*iv[mod%i]%mod;
		ivjc[i]=(ll)ivjc[i-1]*iv[i]%mod;
	}
	read(n),read(m);
	scanf("%s",s+1); x=n/2;
	for (int i=1;i<=n;i++) {
		if (s[i]=='?') cnt++;
		else if ((s[i]=='w')==i%2) x--;
	}
	//printf("%d\n",x);
	for (int i=0;i<=cnt;i++) if (i%2==abs(x)%2) {
		update(ans,(ll)abs(x-i)*C(cnt,i)%mod);
		//printf("%d\n",ans);
	}
	ans=(ll)ans*ksm(iv[2],cnt)%mod;
	printf("%d\n",ans);
	return 0;
}
/*
  REMEMBER:
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Array size? Integer overflow? Time complexity? Memory usage? Precision error?
*/