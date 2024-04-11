#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(3e5)+10;
int T,n,tr[maxn];
vector<int> a[maxn],b[maxn];
void add(int x,int delta) {
	for (;x<=n;x+=x&(-x)) tr[x]=max(tr[x],delta);
}
int query(int x) {
	int res=0;
	for (;x>0;x-=x&(-x)) res=max(res,tr[x]);
	return res;
}
bool solve() {
	for (int i=1;i<=n;i++) tr[i]=0;
	for (int i=1;i<=n;i++) {
		if (a[i].size()!=b[i].size()) return 0;
		for (int j=a[i].size()-1;j>=0;j--) {
			if (query(a[i][j])>b[i][j]) return 0;
			add(a[i][j],b[i][j]);
		}
	}
	return 1;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n); int x,y;
		for (int i=1;i<=n;i++)
			a[i].clear(),b[i].clear();
		for (int i=1;i<=n;i++) {
			read(x);
			a[x].push_back(i);
		}
		for (int i=1;i<=n;i++) {
			read(x);
			b[x].push_back(i);
		}
		if (solve()) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}