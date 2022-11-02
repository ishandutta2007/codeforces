#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=110;
int T,n,m,cnt[maxn][30],c[30];
char s[maxn],t[maxn];
bool flag,flag2;
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		scanf("%s",s+1);
		scanf("%s",t+1);
		n=strlen(s+1);
		m=strlen(t+1);
		for (int i=1;i<=m;i++) {
			for (int j=0;j<26;j++)
				cnt[i][j]=cnt[i-1][j];
			cnt[i][t[i]-'a']++;
		}
		memset(c,0,sizeof(c));
		for (int i=1;i<=n;i++) c[s[i]-'a']++;
		flag=0;
		for (int i=1;i<=m;i++)
		for (int j=i;j<=m;j++) {
			flag2=1;
			for (int k=0;k<26;k++)
				if (cnt[j][k]-cnt[i-1][k]!=c[k]) { flag2=0; break; }
			if (flag2) { flag=1; break; }
		}
		if (flag) printf("YES\n");
		else printf("NO\n");
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