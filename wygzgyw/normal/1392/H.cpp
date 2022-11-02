#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int mod=998244353;
const int maxn=(2e6)+10;
int n,m,ans;
int iv[maxn];
void update(int &x,int y) { x+=y; if (x>=mod) x-=mod; }
int main() {
//	freopen("1.txt","r",stdin);
	iv[0]=iv[1]=1;
	for (int i=2;i<maxn;i++) iv[i]=(ll)(mod-mod/i)*iv[mod%i]%mod;
	read(n),read(m);
	for (int i=1;i<=n;i++) update(ans,iv[i]);
	ans=((ll)ans*m%mod+1)*((ll)n*iv[m+1]%mod+1)%mod;
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