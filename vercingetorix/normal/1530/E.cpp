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

const int mod = 31607;
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
    scanf("%d\n", &t);
    char c[100050];
    while(t--) {
        scanf("%s", c);
        string s(c);
        int n = s.size();
        vi cnt(26,0);
        for(auto x : s) {
            cnt[x-'a']++;
        }
        int done = 0;
        forn(i,0,26) if(cnt[i] == 1) {
            int pt =0 ;
            while(s[pt] != 'a'+i) pt++;
            swap(s[0],s[pt]);
            sort(s.begin()+1, s.end());
            printf("%s\n", s.c_str());
            done = 1;
            break;
        }
        if(done) continue;
        int mn = 0;
        while(cnt[mn] == 0) mn++;
        int k = cnt[mn];
        string ans(1,'a'+mn);
        cnt[mn]--;
        int last = mn;
        int fp = 1;
        
        if(k == n) ans = string(n,'a'+mn);
        else forn(jj,0,n-1) {
            int cur = mn;
            if(fp) {
                if(k-2 > n-k && k<n) {
                    cur++;
                    while(cnt[cur] == 0) cur++;
                    if(cnt[cur] +k== n) {
                        ans += string(cnt[cur], 'a'+cur);
                        ans += string(cnt[mn],'a'+mn );
                        break;
                    }
                }
             }
            while(cnt[cur]==0 || (last == mn && fp == 0 && ('a'+cur) == ans[1])) cur++;
            ans.pb('a'+cur);
            cnt[cur]--;
            last = cur;
            fp = 0;
        }
        printf("%s\n", ans.c_str());
    }
    
    
}