#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
#define MP make_pair
typedef long long ll;
const int mod=998244353;
const int maxn=(1e5)+10;
int T,n,a[maxn],ans;
vector<pair<int,int> > f,g;
void update(int &x,int y) { x+=y; if (x>=mod) x-=mod; }
int up(int x,int y) { if (x%y==0) return x/y; return x/y+1; }
int main() {
	read(T); while (T--) {
		read(n); for (int i=1;i<=n;i++) read(a[i]);
		ans=0; g.clear();
		for (int i=n;i>=1;i--) {
			f.push_back(MP(a[i],1));
			for (pair<int,int> &A : g) {
				int t=up(a[i],A.first);
				if ((int)f.size()&&f.back().first==a[i]/t) update(f.back().second,A.second);
				else f.push_back(MP(a[i]/t,A.second));
				update(ans,(ll)i*(t-1)%mod*A.second%mod);
			}
			g.swap(f); f.clear();
		}
		printf("%d\n",ans);
	}
	return 0;
}