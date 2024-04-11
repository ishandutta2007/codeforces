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

#define all(c) (c).begin(),(c).end()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair
vi good(26,0);

bool fit(char let, char a) {
    if('a'<=a && a<='z') return let == a;
    else if(a == '?') return good[let-'a'] == 1;
    return false;
}

void no() {
    printf("NO\n");
}
void yes() {
    printf("YES\n");
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    string gd;
    getline(cin, gd);
    for(auto x : gd) good[x-'a'] = 1;
    string t;
    getline(cin, t);
    int as = -1;
    int n = t.size();
    forn(i,0,t.size()) if(t[i]=='*') as = i;
    int q;
    scanf("%d\n", &q);
    forn(i,0,q) {
        string s;
        getline(cin, s);
        if(as == -1) {
            if(s.size()!=t.size()) no();
            else {
                bool can = true;
                forn(j,0,n) {
                    if(!fit(s[j], t[j])) can = false;
                }
                if(can) yes();
                else no();
            }
        }
        else {
            if(s.size() + 1 < t.size()) no();
            else {
                bool can = true;
                int l = 0;
                int r = n-1;
                int sl = 0;
                int sr = s.size() - 1;
                while(l < as) {
                    if(!fit(s[sl], t[l])) {
                        can = false;
                        break;
                    }
                    l++;
                    sl++;
                }
                while(r > as) {
                    if(!fit(s[sr], t[r])) {
                        can = false;
                        break;
                    }
                    r--;
                    sr--;
                }
                if(!can) no();
                else {
                    int gc = 0;
                    forn(j,sl,sr+1) gc+=good[s[j]-'a'];
                    if(gc == 0) yes();
                    else no();
                }
            }
        }
    }
    
//    forn(i,0,q) {
//        string s;
//        getline(cin, s);
//        int n = s.size();
//        vi cum(n,0);
//        forn(i,0,n) {
//            if(i>0) cum[i] = cum[i-1];
//            cum[i] += good[s[i]-'a'];
//        }
//        int l = 0;
//        int r = t.size() - 1;
//        int sl = 0;
//        int sr = n-1;
//        bool can = true;
//        while(l <= r) {
//            if(t[l] == '*') break;
//            else if(sl <= sr && fit(s[sl], t[l])) {
//                l++;
//                sl++;
//            }
//            else {
//                can = false;
//                break;
//            }
//        }
//        while(r>=l) {
//            if(t[r] == '*') break;
//            else if(sl <= sr && fit(s[sr], t[r])) {
//                r--;
//                sr--;
//            }
//            else {
//                can = false;
//                break;
//            }
//        }
//        if(!can) {
//            printf("NO\n");
//            continue;
//        }
//        else {
//            if(r < l) {
//                if(sr>=sl) printf("NO\n");
//                else printf("YES\n");
//                continue;
//            }
//            int ngood = cum[sr];
//            if(sl>0) ngood -= cum[sl-1];
//            if(ngood > 0) printf("NO\n");
//            else printf("YES\n");
//        }
//    }
    
    
}