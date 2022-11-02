#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(1e5)+10;
int n,cnt[30];
ll T;
char s[maxn];
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(T);
	scanf("%s",s+1);
	T-=(1LL<<(s[n]-'a'))-(1LL<<(s[n-1]-'a'));
	n-=2;
	if (!n) { if (!T) puts("Yes"); else puts("No"); return 0; }
	for (int i=1;i<=n;i++) cnt[s[i]-'a']++;
	for (int i=0;i<=25;i++) T+=(ll)cnt[i]*(1LL<<i);
	for (int i=25;i>=0;i--)
	for (int j=1;j<=cnt[i];j++)
		if (T>=(1LL<<i+1)) T-=(1LL<<(i+1));
	if (!T) puts("Yes");
	else puts("No");
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