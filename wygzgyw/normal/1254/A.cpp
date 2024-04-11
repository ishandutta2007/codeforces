#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
int T,n,m,k,F;
char s[110][110],ans[110][110],id[70];
int main() {
	//freopen("1.txt","r",stdin);
	for (int i=1;i<=26;i++) id[i]='a'+i-1;
	for (int i=27;i<=52;i++) id[i]='A'+i-27;
	for (int i=53;i<=62;i++) id[i]='0'+i-53;
	int x,y,cnt,pos,r,a,b,F;
	read(T);
	while (T--) {
		read(n); read(m); read(k);
		r=0;
		for (int i=1;i<=n;i++) {
			scanf("%s",s[i]+1);
			for (int j=1;j<=m;j++)
				if (s[i][j]=='R') r++;
		}
		a=r/k;
		if (r%k==0) b=a; else b=a+1;
		x=1,y=1,cnt=0,pos=1;
		F=0;
		while (1) {
			if (s[x][y]=='R') cnt++;
			if (cnt>a&&pos<=k-(r%k)) pos++,cnt=1;
			else if (cnt>b) pos++,cnt=1;
			ans[x][y]=id[pos];
			F++;
			if (F==n*m) break;
			if (x&1) {
				if (y==m) x++;
				else y++;
			} else {
				if (y==1) x++;
				else y--;
			}
		}
		for (int i=1;i<=n;i++) ans[i][m+1]=0;
		for (int i=1;i<=n;i++) printf("%s\n",ans[i]+1);
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