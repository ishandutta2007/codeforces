#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

using namespace std;
template<class T>
using indexed_set =  tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
typedef long long ll;
#define all(x) x.begin(), x.end()
#define trav(i, x) for(auto &i : x)
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define eb emplace_back
#define FOR(i, N) for(int i = 0; i < (N); i++)
const ll mod = 1e9 + 7;


void solve() 
{
	int ans=0;
	int n; scanf("%d", &n);
	vector<int> a(n);
	trav (i, a) {
		scanf("%d", &i);
	}
	
	sort(a.begin(), a.end());
	int cur=0;
	trav (i, a) {
		cur++;
		if(cur >= i) {
			ans++;
			cur = 0;
		}
	}
	printf("%d\n", ans);
}
int main() {

    int t = 1, i = 1;
    scanf("%d", &t);
    while(t--) {
        // printf("Case #%d: ", i)
        solve();
        i++;
    }
}