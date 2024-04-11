
#include<bits/stdc++.h>
#include<bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define I(x, a) for(auto x : a)
#define F(i, l, r) for(auto i = l; i < r; ++i)
#define E(i, l, r) for(auto i = l; i <= r; ++i)
#define DF(i, l, r) for(auto i = l; i >= r; --i)
#define clean(a) memset((a),0,sizeof (a))
#define sync ios_base::sync_with_stdio(0);cin.tie(0)
#define all(x) (x).begin(),(x).end()
#define ret return
#define cont continue
#define brk break
#define ins insert

const int N = 102;

int n;
int cnt[N];
vector<int> who[N];

signed main(){
	sync;
	cin >> n;
	F(i, 0, n){
		int k;
		cin >> k;
		F(j, 0, k){
			int x;
			cin >> x;
			++cnt[x];
		}
	}
	F(i, 0, N)if(cnt[i] == n)cout << i << ' ';
	ret 0;
}