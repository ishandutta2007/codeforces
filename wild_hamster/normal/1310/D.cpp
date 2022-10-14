
#include <utility>
#include <iostream>
#include <cmath>
#include <deque>
#include <string>
#include <time.h>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <bitset>
#include <fstream>

#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
#define N 1000000
#define OFF 200001
#define MOD 1000000007
#define C 13000
#define NN 1000000
ll n, x, k, z, m, pos, q, ans_v, y, root;
ll d[85][85];
ll a[85], b[85];
ll dp[12][85];
vector<ll> comp[2];
string seed = "dsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgvjkdrghhrgekjrghekjghjkerhgekjrhgkjerhgjkehrgkjhjkdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdfkjghdjkfghkejrhgkjerhgiuehrgiuerhyitheryufhaisuchuisahfiuahsfiuahsiudsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgvjkdrghhrgekjrghekjghjkerhgekjrhgkjerhgjkehrgkjhjkdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdfkjghdjkfghkejrhgkjerhgiuehrgiuerhyitheryufhaisuchuisahfiuahsfiuahsiudsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgvjkdrghhrgekjrghekjghjkerhgekjrhgkjerhgjkehrgkjhjkdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdfkjghdjkfghkejrhgkjerhgiuehrgiuerhyitheryufhaisuchuisahfiuahsfiuahsiudsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgvjkdrghhrgekjrghekjghjkerhgekjrhgkjerhgjkehrgkjhjkdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdfkjghdjkfghkejrhgkjerhgiuehrgiuerhyitheryufhaisuchuisahfiuahsfiuahsiudsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdrkgjkdjgkjdfjgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgvjkdrghhrgekjrghekjghjkerhgekjrhgkjerhgjkehrgkjhjkdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdfkjghdjkfghkejrhgkjerhgiuehrgiuerhyitheryufhaisuchuisahfiuahsfiuahsiudsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgvjkdrghhrgekjrghekjghjkerhgekjrhgkjerhgjkehrgkjhjkdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdfkjghdjkfghkejrhgkjerhgiuehrgiuerhyitheryufhaisuchuisahfiuahsfiuahsiudsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgvjkdrghhrgekjrghekjghjkerhgekjrhgkjerhgjkehrgkjhjkdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdfkjghdjkfghkejrhgkjerhgiuehrgiuerhyitheryufhaisuchuisahfiuahsfiuahsiudsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgvjkdrghhrgekjrghekjghjkerhgekjrhgkjerhgjkehrgkjhjkdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdfkjghdjkfghkejrhgkjerhgiuehrgiuerhyitheryufhaisuchuisahfiuahsfiuahsiudsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrgdsflghjsdfjkghsejkrhjsklerjghklserjglksejgklerlrg";
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> d[i][j];
        }
    }
    ll hyu = 0;
    for (int i = 0; i < seed.size(); i++) {
        hyu = (hyu * 26 + seed[i] - 'a') % MOD;
    }
    srand(hyu);
    ll ans = MOD;
    for (int ii = 0; ii < 10000; ii++) {
        for (int j = 0; j < n; j++) {
            a[j] = j + 1;
        }
        for (int j = 0; j < 1000; j++) {
            ll x = rand() % (n - 1) + 1;
            ll y = rand() % (n - 1) + 1;
            swap(a[x], a[y]);
        }
        for (int i = 0; i < 2; i++) {
            comp[i].clear();
        }
        for (int i = 0; i < n; i++) {
            if (i < n/2) {
                comp[0].push_back(a[i]);
            } else {
                comp[1].push_back(a[i]);
            }
        }
        for (int j = 0; j <= n; j++) {
            for (int i = 0; i <= k; i++) {
                dp[i][j] = MOD;
            }
        }
        dp[0][1] = 0;
        for (int i = 0; i < k; i++) {
            ll id = i % 2;
            ll sz = comp[id].size();
            for (auto v : comp[id]) {
                for (auto to : comp[id ^ 1]) {
                    dp[i+1][to] = min(dp[i+1][to], dp[i][v] + d[v][to]);
                }
            }
        }
        ans = min(ans, dp[k][1]);
    }
    cout << ans << "\n";
    return 0;
}