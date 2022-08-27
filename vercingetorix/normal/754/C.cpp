#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <queue>
#include <cstring>
#include <set>
#include <list>
#include <map>
#include <random>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef vector<vvi> vvvi;
typedef vector<vll> vvll;
typedef std::vector<std::pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

const long long mod = 1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair
bool islit(char c) {
    if('a'<=c && c<='z') return true;
    if('0'<=c && c<='9') return true;
    if('A'<=c && c<='Z') return true;
    return false;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int taf;
    scanf("%d\n", &taf);
    forn(iad,0,taf) {
        int n;
        scanf("%d\n", &n);
        vs s(n);
        map<string, int> name;
        set<string> isname;
        forn(i,0,n) {
            cin>>s[i];
            isname.insert(s[i]);
            name[s[i]] = i;
        }
        int m;
        scanf("%d\n", &m);
        vs sen(m);
        vs mes(m);
        vvi can(m, vi(n,1));
        forn(i,0,m) {
            string t;
            getline(cin, t);
            int pt = 0;
            while(t[pt]!=':') pt++;
            sen[i] = t.substr(0,pt);
            mes[i] = t.substr(pt+1);
            if(sen[i] != "?") {
                int ind = name[sen[i]];
                forn(j,0,n) {
                    if(j!=ind) can[i][j] = 0;
                }
            }
            int l = 0;
            string ms = mes[i];
            int len = ms.size();
            while(l < len) {
                while(l < len && !islit(ms[l])) l++;
                if(l==len) break;
                int r = l+1;
                while(r < len && islit(ms[r])) r++;
                string word = ms.substr(l,r-l);
                if(isname.find(word) != isname.end()) {
                    int ind = name[word];
                    can[i][ind] = 0;
                }
                l= r;
            }
        }
        vi sum(m,0);
        int last  = -1;
        forn(i,0,n) {
            sum[0] += can[0][i];
            if(can[0][i]) last = i;
        }
        bool imp = false;
        if(sum[0] == 0) imp = true;
        if(sum[0] == 1 && m > 1) can[1][last] = 0;
        forn(i,1,m) {
            forn(j,0,n) {
                sum[i] += can[i][j];
                if(can[i][j]) last = j;
            }
            if(sum[i] == 0) imp = true;
            else if(sum[i] == 1 && i < m-1) can[i+1][last] = 0;
        }
        if(imp) {
            printf("Impossible\n");
            continue;
        }
        vs ans;
        for(int i = m-1; i>=0; i--) {
            forn(j,0,n) {
                if(can[i][j]) {
                    ans.pb(s[j]+":"+mes[i]);
                    if(i>0) can[i-1][j] = 0;
                    break;
                }
            }
        }
        reverse(all(ans));
        for(auto u : ans) printf("%s\n", u.c_str());
        
    }
    
}