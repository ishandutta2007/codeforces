#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; int f=1; char ch=getchar();
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int INF=1e9;
int T,b[60],n,m;
char s[60],t[60];
vector<int> q;
int cnt[60];
vector<int> g[60];
int tot;
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		scanf("%s",s+1);
		n=strlen(s+1);
		memset(cnt,0,sizeof(cnt));
		for (int i=1;i<=n;i++) cnt[s[i]-'a']++;
		read(m);
		for (int i=1;i<=m;i++) read(b[i]);
		tot=0;
		while (1) {
			q.clear();
			for (int i=1;i<=m;i++)
				if (b[i]==0) q.push_back(i),b[i]=INF;
			if (!q.size()) break;
			g[++tot]=q;
			for (int i=1;i<=m;i++)
				for (int j=0;j<q.size();j++)
					b[i]-=abs(i-q[j]);
		}
		int pos=25;
		for (int i=1;i<=tot;i++) {
			while (cnt[pos]<g[i].size()) pos--;
			for (int j=0;j<g[i].size();j++) t[g[i][j]]=pos+'a';
			pos--;
		}
		for (int i=1;i<=m;i++) printf("%c",t[i]);
		printf("\n");
	}
	return 0;
}