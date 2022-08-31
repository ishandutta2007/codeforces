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

const int MAXN = 100000;
vector<int> lst[MAXN];
int parent[MAXN];

void make_set (int v) {
    lst[v] = vector<int> (1, v);
    parent[v] = v;
}

int find_set (int v) {
    return parent[v];
}

void union_sets (int a, int b) {
    a = find_set (a);
    b = find_set (b);
    if (a != b) {
        if (lst[a].size() < lst[b].size())
            swap (a, b);
        while (!lst[b].empty()) {
            int v = lst[b].back();
            lst[b].pop_back();
            parent[v] = a;
            lst[a].push_back (v);
        }
        
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    scanf("%d\n", &n);
    vs s(n);
    forn(i,0,n) {
        getline(cin, s[i]);
        vi cnt(26,0);
        for(auto x : s[i]) cnt[x-'a'] ++;
        forn(j,0,26) if(cnt[j] > 1) {
            printf("NO");
            return 0;
        }
    }
    
    forn(i,0,n) make_set(i);
    vvi sym(26);
    forn(i,0,n) for(auto x : s[i]) sym[x-'a'].pb(i);
    forn(snum,0,26) {
        int k = sym[snum].size();
        forn(i,0,k-1) {
            int a = find_set(sym[snum][i]);
            int b = find_set(sym[snum][i+1]);
            if (a != b) {
                int p = s[a].size();
                int q = s[b].size();
                int pos1 = 0, pos2 = 0;
                while(s[a][pos1] != 'a' + snum) pos1++;
                while(s[b][pos2] != 'a' + snum) pos2++;
                int mxp = max(pos1, pos2);
                int len = max(p-pos1, q-pos2) + mxp;
                string news;
                forn(j,0,len) {
                    int np1 = j + pos1 - mxp;
                    int np2 = j + pos2 - mxp;
                    char c1 = '.';
                    char c2 = '.';
                    if(np1 >= 0 && np1 < p) c1 = s[a][np1];
                    if(np2 >= 0 && np2 < q) c2 = s[b][np2];
                    if(c1 != '.' && c2 != '.' && c1 != c2) {
                        printf("NO");
                        return 0;
                    }
                    else if(c1 != '.') news.pb(c1);
                    else news.pb(c2);
                }
                vi cnt(26,0);
                for(auto x : news) cnt[x-'a'] ++;
                forn(j,0,26) if(cnt[j] > 1) {
                    printf("NO");
                    return 0;
                }
                union_sets(a, b);
                s[find_set(a)] = news;
            }
        }
    }
    vs alls;
    forn(i,0,n) if(!lst[i].empty()) alls.pb(s[i]);
    sort(all(alls));
    string ans;
    for(auto x : alls) ans = ans + x;
    printf("%s", ans.c_str());
    
    
    
    
}