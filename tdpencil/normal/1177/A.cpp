#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iterator>
using namespace __gnu_pbds;
using namespace std;
template <typename T> using oset = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class Fun>
class y_combinator_result {
    Fun fun_;
    public:
    template<class T>
        explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

    template<class ...Args>
        decltype(auto) operator()(Args &&...args) {
            return fun_(std::ref(*this), std::forward<Args>(args)...);
        }
};

template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}


#define ll int64_t


ll fastpow(ll x, ll y) {
    ll res = 1;
    for(; y ; y >>= 1) {
        if(y&1)
            res = res * x;
        x=x*x;
    }
    return res;
}
ll below(ll var) {
    int v = 1;
    ll res = 0;
    while(var > 0) {
        res += var;

        var -= fastpow(10, v);
        v += 1;
    }
    return res;
}

#undef ll

#define ll long long
void solve() 
{
    ll K; cin >> K;
	int number = -1;
    for(int i = 1; i <= int(1e7)+15; i++) {
		int b = to_string(i).size();
		if(K - b <= 0) {
			number = i;
			break;
		}
		
		number = i;
		K -= b;
	}
	
	string num = to_string(number);
	//cout << num << "\n";
	//cout << K << "\n";
	cout << num[K - 1] << "\n";
}

int main() {
    // #define take_input TAKE_THE_L    
    cin.tie(0)->sync_with_stdio(0);

    int T = 1;

#ifdef take_input
    cin >> T;
#endif

    for(;T; --T)
        solve();
    
}