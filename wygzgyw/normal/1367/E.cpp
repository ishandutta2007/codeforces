#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; int f=1; char ch=getchar();
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
int T,n,k,tmp;
vector<int> cnt,c,d;
char s[2010];
bool vis[2010],flag;

int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n); read(k);
		scanf("%s",s+1);
		cnt.resize(30);
		for (int i=0;i<30;i++) cnt[i]=0;
		for (int i=1;i<=n;i++) cnt[s[i]-'a']++;
		sort(cnt.begin(),cnt.end());
		for (int len=n;len>=1;len--) {
			for (int i=0;i<len;i++) vis[i]=0;
			d.clear();
			for (int i=0;i<len;i++) if (!vis[i]) {
				tmp=0;
				int x=i;
				while (1) {
					tmp++; vis[x]=1;
					x=(x+k)%len;
					if (x==i) break;
				}
				d.push_back(tmp);
			}
			sort(d.begin(),d.end());
			c=cnt;
			flag=1;
			while (d.size()) {
				if (d.back()>c.back()) { flag=0; break; }
				c.back()-=d.back();
				d.pop_back();
				sort(c.begin(),c.end());
			}
			if (flag) { printf("%d\n",len); break; }
		}
	}
	return 0;
}