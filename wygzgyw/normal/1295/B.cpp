#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(2e5)+10;
int T,n,x,s[maxn],cnt[maxn];
char S[maxn];
ll ans;
int main() {
//	freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n);
		read(x);
		scanf("%s",S+1);
		for (int i=-n;i<=n;i++) cnt[i+n]=0;
		for (int i=1;i<=n;i++) {
			s[i]=s[i-1];
			if (S[i]=='1') s[i]--;
			else s[i]++;
			cnt[s[i]+n]++;
		}
	//	for (int i=1;i<=n;i++) printf("%d ",s[i]); printf("\n");
		if (s[n]==0) {
			if (-n<=x&&x<=n) {
				if (cnt[x+n]) printf("-1\n");
				else printf("0\n");
			} else printf("0\n");
		} else {
			ans=0;
			for (int i=0;i<n;i++) {
				if (abs(x-s[i])%abs(s[n])==0) {
					if ((x-s[i])/s[n]>=0) ans++;
				}
			}
			printf("%lld\n",ans);
		}
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