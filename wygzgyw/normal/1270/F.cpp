#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(2e5)+10;
int n,block,tot,d[maxn],delta;
char S[maxn];
ll ans;
int s[maxn],tmp;
vector<int> cnt;
int main() {
	//freopen("1.txt","r",stdin);
	scanf("%s",S+1);
	n=strlen(S+1);
	block=sqrt(n);
	for (int i=1;i<=n;i++) {
		s[i]=s[i-1]+S[i]-'0';
		if (S[i]=='1') d[++tot]=i;
	}
	d[++tot]=n+1;
	cnt.resize(n*block+n+1);
	for (int i=1;i<=block;i++) {
		delta=i*n;
		cnt[delta]++;
		for (int j=1;j<=n;j++) {
			tmp=j-i*s[j];
			ans+=cnt[tmp+delta];
			cnt[tmp+delta]++;
		}
		cnt[delta]--;
		for (int j=1;j<=n;j++) {
			tmp=j-i*s[j];
			cnt[tmp+delta]--;
		}
	}
	for (int i=1;i<=n;i++)
	for (int j=1,l,r;j<=n/block&&s[i-1]+j+1<=tot;j++) {
		l=d[s[i-1]+j]-i+1;
		r=d[s[i-1]+j+1]-i;
		l=max(l,j*(block+1));
		if (l<=r) ans+=r/j-(l-1)/j;
	}
	printf("%lld\n",ans);
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