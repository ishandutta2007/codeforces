#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, n) for(auto &i : n)
#define SZ(x) (int)(x).size()
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<
T,
null_type,
less<T>,
rb_tree_tag,
tree_order_statistics_node_update>;

int t;
int n, A[500005];

int my[500005];
int ans[500005];

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> t;
	while(t--){
		std::cin >> n;
		std::vector<PII> p;
		FOR(i, n){
			std::cin >> A[i];
			if(A[i] == -1) A[i] = i+1;
			else A[i]--;
			p.push_back(MP(i, A[i]));
		}
		std::sort(p.begin(), p.end());
		std::stack<int> stack;
		bool wrong = false;
		TRAV(i, p){
			while(SZ(stack) > 0 && stack.top() <= i.X) stack.pop();
			if(SZ(stack) > 0 && stack.top() < i.Y){
				wrong = true;
				break;
			}
			stack.push(i.Y);
		}
		if(wrong){
			std::cout << -1 << "\n";
			continue;
		}
		ordered_set<int> fre;
		FOR(i, n) fre.insert(i);
		FOR(i, n){
			auto it = fre.find_by_order(A[i]-i-1);
			std::cout << *it+1 << " ";
			fre.erase(it);
		}
		std::cout << "\n";

	}
	return 0;
}