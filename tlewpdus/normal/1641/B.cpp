#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1000000007;

int N;
int A[600];
map<int,int> cnt;

int main() {
	int tt;

	scanf("%d",&tt);
	while(tt--) {
		scanf("%d",&N);
		for (int i=0;i<N;i++) {
			scanf("%d",&A[i]);
			cnt[A[i]]++;
		}
		bool mang = false;
		for (int i=0;i<N;i++) {
			if (cnt[A[i]]%2) {
				mang = true;
			}
		}
		cnt.clear();
		if (mang) {
			puts("-1");
			continue;
		}
		int base = 0, s = 0;
		vector<pii> ans;
		vector<int> lens;
		while(s<N) {
			int t = 0;
			for (int i=s+1;i<N;i++) {
				if (A[i]==A[s]) {
					t = i;
					break;
				}
			}
			for (int i=s+1;i<t;i++) {
				ans.emplace_back(t+i-s-s+base,A[i]);
			}
			lens.push_back(t-s);
			vector<int> tmp;
			for (int i=s+1;i<t;i++) tmp.push_back(A[i]);
			for (int i=0;i<tmp.size();i++) A[t-i] = tmp[i];
			base +=2*(t-s);
			s += 2;
		}
		printf("%d\n",ans.size());
		for (pii &e : ans) printf("%d %d\n",e.first, e.second);
		printf("%d\n",lens.size());
		for (int &e : lens) printf("%d ",e*2); puts("");
	}

	return 0;
}