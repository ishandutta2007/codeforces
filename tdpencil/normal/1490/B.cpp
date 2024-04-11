#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;
typedef long long ll; 
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
 
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

int cnt[3];
void solve() {
    int N; cin >> N;
    vector<int> A(N);

    for(auto &a: A)
    	cin >> a;

    for(auto &a: A)
    	cnt[a%3]++;



    int mid = N / 3;
    int ans = 0;
    for(int i = 0; i < 3; i++) {
    	if(cnt[i] > mid) {
    		for(int j = 0; j < N; j++) {
    			if(cnt[i] <= mid) break;
    			int p = A[j]%3;
    			if(p == i) {
    				for(int k = 0; k < 3; k++) {
    					A[j]++;
    					ans++;
    					if(cnt[A[j]%3]<mid) {
    						cnt[A[j]%3]++;
    						cnt[i]--;
    						break;
    					}
    				}
    			}
    		}
    	}
    }
    cnt[0]=0;
   	cnt[1]=0;
   	cnt[2]=0;

    // O(N*3*3)

    cout << ans << "\n";



}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    
    while(T--)
        solve();
}