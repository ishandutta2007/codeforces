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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    vvi pr(100000);
    vi dig={0,4,7};
    vi nums;
    
    map<int, string> a;
    forn(i,0,7) {
        forn(j,0,7-i) {
            a[4*i+7*j] = string(i,'4')+string(j,'7')+string(6-i-j,'0');
        }
    }
    map<int,string> b;
    for(auto u:a) {
        for(auto v:a) {
            for(auto c:a) {
                for(auto d:a) {
                    b[u.first+10*v.first+100*c.first+1000*d.first] = d.second+c.second+v.second+u.second;
                }
            }
        }
    }
    vll d10(1,1ll);
    forn(i,0,18) d10.pb(10ll*d10.back());
//    vi u(100000,0);
//    cout<<b[1024];
//    forn(i, 1, 100000) if(!u[i]) cout<<i<<endl;
    int t;
    scanf("%d", &t);
    forn(i,0,t) {
        ll n;
        scanf("%lld", &n);
        if(n<45000) {
            if(b[n]=="") {
                printf("-1\n");
                continue;
            }
            else {
                string cans = b[n];
                vs ans(6);
                forn(i,0,6) forn(j,0,4) ans[i].pb(cans[i+j*6]);
                forn(i,0,6) while(ans[i].size()>1 && ans[i][0] == '0') ans[i]=ans[i].substr(1);
                forn(i,0,5) printf("%s ", ans[i].c_str());
                printf("%s\n", ans[5].c_str());
            }
        }
        else {
            string s = to_string(n);
            string cans;
            if(s.size() >= 5) {
                if(s.substr(0,2) > "44") {
                    cans = "400000";
                    s[0]-=4;
                    if(s.substr(0,2) > "44") {
                        cans[1]='4';
                        s[0]-=4;
                    }
                }
            }
            while(s.size() > 5) {
                string f2 = s.substr(0,2);
                int cap = 10*int(f2[0]-'0') + int(f2[1]-'0');
                // 5 <= cap < 45
                if(cap <= 7) {
                    cans+="400000";
                    s=s.substr(1);
                    s[0]-=4;
                }
                else if(cap<=10) {
                    cans+="700000";
                    s=s.substr(1);
                    s[0] = '0'+(cap-7);
                }
                else if(cap<=11) {
                    cans+="440000";
                    s=s.substr(1);
                    s[0] = '0'+(cap-8);
                }
                else if(cap<=14) {
                    cans+="740000";
                    s=s.substr(1);
                    s[0] = '0'+(cap-11);
                }
                else if(cap<=17) {
                    cans+="770000";
                    s=s.substr(1);
                    s[0] = '0'+(cap-14);
                }
                else if(cap<=19) {
                    cans+="444400";
                    s=s.substr(1);
                    s[0] = '0'+(cap-16);
                }
                else if(cap<=22) {
                    cans+="744400";
                    s=s.substr(1);
                    s[0] = '0'+(cap-19);
                }
                else if(cap<=25) {
                    cans+="774400";
                    s=s.substr(1);
                    s[0] = '0'+(cap-22);
                }
                else if(cap<=28) {
                    cans+="777400";
                    s=s.substr(1);
                    s[0] = '0'+(cap-25);
                }
                else if(cap<=31) {
                    cans+="777700";
                    s=s.substr(1);
                    s[0] = '0'+(cap-28);
                }
                else if(cap<=33) {
                    cans+="774444";
                    s=s.substr(1);
                    s[0] = '0'+(cap-30);
                }
                else if(cap<=36) {
                    cans+="777444";
                    s=s.substr(1);
                    s[0] = '0'+(cap-33);
                }
                else if(cap<=39) {
                    cans+="777744";
                    s=s.substr(1);
                    s[0] = '0'+(cap-36);
                }
                else if(cap<=42) {
                    cans+="777774";
                    s=s.substr(1);
                    s[0] = '0'+(cap-39);
                }
                else {
                    cans+="777777";
                    s=s.substr(1);
                    s[0] = '0'+(cap-42);
                }
            }
            cans+=b[stoi(s)];
            vs ans(6);
            forn(i,0,6) forn(j,0,cans.size()/6) ans[i].pb(cans[i+j*6]);
            forn(i,0,6) while(ans[i].size()>1 && ans[i][0] == '0') ans[i]=ans[i].substr(1);
            forn(i,0,5) printf("%s ", ans[i].c_str());
//            ll sum = 0;
//            forn(i,0,6) sum+=stoll(ans[i]);
            printf("%s\n", ans[5].c_str());
//            printf("%lld\n", sum);
        }
    }
    
    
}