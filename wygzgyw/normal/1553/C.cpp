#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
int T,d[15],tot,ans,tmp;
char s[15];
int suf[15][2];
int main() {
	for (int i=9;i>=0;i--) {
		suf[i][0]=suf[i+1][0],suf[i][1]=suf[i+1][1];
		suf[i][i&1]++;
	}
	read(T); while (T--) {
		scanf("%s",s);
		int tot=0,ans=1e9;
		for (int i=0;i<10;i++) if (s[i]=='?') d[tot++]=i;
		for (int t=0;t<(1<<tot);t++) {
			for (int i=0;i<tot;i++) if (t>>i&1) s[d[i]]='1'; else s[d[i]]='0';
			tmp=0;
			int a=0,b=0;
			for (int i=0;i<10;i++) {
				if (i&1) a+=s[i]-'0'; else b+=s[i]-'0'; tmp=i+1;
				if (a+suf[i+1][1]<b||b+suf[i+1][0]<a) break;
			}
			ans=min(ans,tmp);
		}
		printf("%d\n",ans);
	}
	return 0;
}