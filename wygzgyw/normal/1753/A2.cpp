// wygzgyw
#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
template <typename T> void write(T t) {
	if (t<0) { putchar('-'); write(-t); return; }
	if (t>9) write(t/10);
	putchar('0'+t%10);
}
template <typename T> void writeln(T t) { write(t); puts(""); }
#define MP make_pair
const int maxn=(2e5)+10;
int T,n,a[maxn];
vector<pair<int,int> > ans;
int d[maxn];
bool vis[maxn];
int main() {
	read(T);
	while (T--) {
		read(n);
		int tot=0;
		for (int i=1;i<=n;i++) {
			read(a[i]); vis[i]=0;
			if (a[i]) d[++tot]=i;
		}
		ans.clear();
		if (tot%2==1) { puts("-1"); continue; }
		for (int i=1;i<tot;i+=2) {
			int x=d[i],y=d[i+1];
			if (a[x]!=a[y]) {
				ans.push_back(MP(x,x));
				if (x+1<=y-1) ans.push_back(MP(x+1,y-1));
				ans.push_back(MP(y,y));
			} else {
				if (x%2==y%2) {
					ans.push_back(MP(x,x));
					ans.push_back(MP(x+1,y));
				} else ans.push_back(MP(x,y));
			}
		}
		for (pair<int,int> &A : ans) for (int i=A.first;i<=A.second;i++) vis[i]=1;
		for (int i=1;i<=n;i++) if (!vis[i]) ans.push_back(MP(i,i));
		sort(ans.begin(),ans.end());
		printf("%d\n",(int)ans.size());
		for (pair<int,int> &A : ans) printf("%d %d\n",A.first,A.second);
	}
	return 0;
}