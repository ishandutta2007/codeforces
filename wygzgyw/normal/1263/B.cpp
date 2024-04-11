#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
int T,n,ans;
map<string,bool> cnt;
string s[20];
bool ck(int k) {
	for (int i=1;i<=n;i++)
		if (i!=k&&s[i]==s[k]) return 0;
	return 1;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n);
		for (int i=1;i<=n;i++) cin>>s[i];
		cnt.clear(); ans=0;
		for (int i=1;i<=n;i++) {
			if (cnt[s[i]]) {
				ans++;
				for (char ch='0';ch<='9';ch++) {
					s[i][0]=ch;
					if (ck(i)) break;
				}
			}
			cnt[s[i]]=1;
		}
		printf("%d\n",ans);
		for (int i=1;i<=n;i++) cout<<s[i]<<endl;
	}
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