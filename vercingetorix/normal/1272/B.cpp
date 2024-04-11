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
#define srt(c) sort(all(c))
#define srtrev(c) sort(all(c)); reverse(all(c))
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    char c[1000000];
    scanf("%d\n", &t);
    while(t--) {
        scanf("%s", c);
        string s(c);
        map<char, int> cnt;
        for(auto x : s) cnt[x]++;
        int can = 1;
        forn(i,0,4) {
            char x = "LUDR"[i];
//            cout<<x<<cnt[x]<<endl;
            if(cnt[x] == 0) can = 0;
        }
        if(can == 0) {
            if(cnt['U'] > 0 && cnt['D'] > 0) {
                cout<<"2\n";
                cout<<"DU\n";
            }
            else if(cnt['R'] > 0 && cnt['L'] > 0) {
                cout<<"2\n";
                cout<<"RL\n";
            }
            else {
                cout<<"0\n";
            }
            continue;
        }
        else {
            int lr = min(cnt['L'], cnt['R']);
            int ud = min(cnt['U'], cnt['D']);
            cout<<2*(lr+ud)<<endl;
            forn(i,0,lr) cout<<"R"; forn(i,0,ud) cout<<"U"; forn(i,0,lr) cout<<"L"; forn(i,0,ud) cout<<"D";
            cout<<endl;
        }
        
    }
    
}