#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
int T,n;
int m,cnt[10][10];
char s[310][310];
void solve() {
		for (int a=0;a<3;a++) for (int b=0;b<3;b++)
			if (a!=b&&cnt[1][a]+cnt[0][b]<=m/3) {
				for (int i=1;i<=n;i++) for (int j=1;j<=n;j++)
					if (s[i][j]!='.') {
						if ((i+j)%3==a) s[i][j]='O';
						else if ((i+j)%3==b) s[i][j]='X';
					}
				return;
			}
}
int main() {
	//freopen("1.txt","r",stdin);
	read(T); while (T--) {
		memset(cnt,0,sizeof(cnt)); m=0;
		read(n);
		for (int i=1;i<=n;i++) scanf("%s",s[i]+1);
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=n;j++) if (s[i][j]!='.') {
				m++;
				cnt[s[i][j]=='X'][(i+j)%3]++;
			}
		}
		solve();
		for (int i=1;i<=n;i++) printf("%s\n",s[i]+1);
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