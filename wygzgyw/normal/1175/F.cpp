#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(3e5)+10;
int n,a[maxn],ans;
pair<ll,ll> h[maxn],s[maxn];
pair<ll,ll> t[maxn];
pair<ll,ll> f(int l,int r) {
	return make_pair(s[l-1].first^s[r].first,s[l-1].second^s[r].second);
}
void solve() {
	for (int i=1;i<=n;i++)
		s[i].first=s[i-1].first^h[a[i]].first,
		s[i].second=s[i-1].second^h[a[i]].second;
	int r,mx;
	for (int i=1;i<=n;i++)
		if (a[i]==1) {
			r=i+1,mx=a[i];
			while (r<=n&&a[r]!=1) {
				mx=max(mx,a[r]);
				if (r-mx+1>=1&&f(r-mx+1,r)==t[mx])
					ans++;
				r++;
			}
		}
}
int main() {
	//freopen("1.txt","r",stdin);
	srand(time(0));
	read(n); ll tmp=0;
	for (int i=1;i<=n;i++) {
		read(a[i]);
		tmp^=a[i];
	}
	for (int i=1;i<maxn;i++) {
		h[i].first=rand()^tmp;
		h[i].second=rand()^tmp;
		t[i].first=t[i-1].first^h[i].first;
		t[i].second=t[i-1].second^h[i].second;
	}
	solve();
	reverse(a+1,a+n+1);
	solve();
	for (int i=1;i<=n;i++)
		if (a[i]==1) ans++;
	printf("%d\n",ans);
	return 0;
}