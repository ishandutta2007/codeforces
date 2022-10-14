#include <algorithm>
#include <unordered_set>
#include <array>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <unordered_map>
#include <stack>
#include <ostream>
#include <istream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
const int64_t inf = 1e12;
using namespace std;
#define ll long long
#define sz(s) (int(s.size()))
#define all(x) x.begin(),x.end()
#define sum(x) accumulate(x.begin(), x.end(), 0LL)
#define vec vector
#define nl '\n'
#define fn function
#define vt vec
#define vl vt<ll>
#define vi vector<int64_t>
#define pr pair
#define pll pr<ll,ll>
#define pii pair<int32_t, int32_t>
#define it int64_t



template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
#define rep(i, a,b) for(int i = a; i < b; i++)
#define dep(i, a,b) for(int i = a-1; i >= b; i--)
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)




int const big_int = 10000;
int const bigm = 100000;
int const bign = 200000;
int const big_graph = 500000;


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct trie {
    vector<trie*> children;
    char val;


    
};
void run_case()
{
    int N, K;
    cin >> N >> K;

    vector<int64_t> A(N);
    for(int i =0; i < N; i++) cin >> A[i];

    vector<it> p(N);
    for(int i = 0; i < K; i++) {
        int x;
        cin >> x;
        p[x-1] = 1;
    }

    while(true) {
        bool nice = false;
        for(int i = 0; i < N-1; i++) {
            if(A[i] > A[i+1] && p[i] == 1) {
                nice = 1;
                swap(A[i], A[i+1]);
            }
        }

        if(!nice) break;
    }

    bool works = true;

    for(int i = 0; i < N-1; i++) {
        if(A[i] > A[i+1]) works = false;
    }
    if(works)
        cout << "YES\n";
    else
        cout << "NO\n";

    // seee if 1 of p can get to the end


}


int main() {
	ios_base::sync_with_stdio(false);
	ios::sync_with_stdio(false);

	cin.tie(0);
	cout.tie(0);

	int t = 1;
	cin >> t;
	while(t--)
		run_case();
}


// 10 nhours at least 
// so basically 6 more hours are neede
//