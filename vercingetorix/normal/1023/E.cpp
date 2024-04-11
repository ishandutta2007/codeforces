#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <cstring>
#include <set>
#include <bitset>
#include <map>
#include <chrono>
#include <random>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef vector<vll> vvll;
typedef std::vector<std::pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

const long long mod = 1000000007;
const unsigned gen_seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 gen(gen_seed);

#define all(c) (c).begin(),(c).end()
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair

int main()
{
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "rt", stdin);
//     freopen("output.txt", "wt", stdout);
// #endif
    int n;
    cin >> n;
    // scanf("%d\n", &n);
    string s;
    vpi tail;
    tail.pb(mp(n, n));
    int x = n;
    int y = n;
    char c[10];
    while(x + y > n + 1) {
        printf("? %d %d %d %d\n", 1, 1, y, x-1);
        fflush(stdout);
        cout.flush();
        cin >> s;
        // scanf("%s\n", c);
        // s = c;

        if(s[0] == 'Y') {
            x--;
        }
        else if(s[0] == 'N' ) y--;
        else {
            cout<< 12424/ 0;
        }
        tail.pb(mp(x,y));
    }
    x = 1;
    y = 1;
    vpi head;
    head.pb(mp(1,1));
    while(x +y < n+1) {
        printf("? %d %d %d %d\n", y+1, x, n, n);
        fflush(stdout);
        cout.flush();
        cin >> s;
        // scanf("%s\n", c);
        // s = c;
        if(s[0] == 'Y') {
            y++;
        }
        else if(s[0] == 'N' ) x++;
        else cout<< 12424/ 0;
        head.pb(mp(x,y));   
    }
    tail.pop_back();
    reverse(all(tail));
    for(auto x : tail) {
        head.pb(x);
    }
    string ans = "";
    forn(i,0,2*n-2) {
        if(head[i].first == head[i+1].first) ans.pb('D');
        else ans.pb('R');
    }
    cout<<"! "<<ans;
    fflush(stdout);
    cout.flush();
}