#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(5e5)+10;
const int mod=(1e9)+7;
int T,n,cnt[70],mi[70];
ll a[maxn];
int ans,s1,s2;
void update(int &x,int y) {
	x+=y; if (x>=mod) x-=mod;
}
int main() {
	//freopen("1.txt","r",stdin);
	mi[0]=1;
	for (int i=1;i<=65;i++) mi[i]=(ll)mi[i-1]*2%mod;
	read(T);
	while (T--) {
		read(n); ans=0;
		memset(cnt,0,sizeof(cnt));
		for (int i=1;i<=n;i++) {
			read(a[i]);
			for (int j=0;j<=62;j++)
				if ((a[i]>>j)&1) cnt[j]++;
		}
		for (int i=1;i<=n;i++) {
			s1=s2=0;
			for (int j=0;j<=62;j++) {
				if ((a[i]>>j)&1) {
					update(s1,(ll)cnt[j]*mi[j]%mod);
					update(s2,(ll)mi[j]*n%mod);
				} else update(s2,(ll)cnt[j]*mi[j]%mod);
			}
			update(ans,(ll)s1*s2%mod);
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Interger overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/