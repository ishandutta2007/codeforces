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
    int n;
    set<int> x;
    map<int,int> cnt;
//    scanf("%d\n", &n);
    cin>>n;
    vector<string> ans;
    vector<int> ans2;
    forn(i,0,n) {
        string s;
        int a;
        cin>>s;
        if(s == "insert") {
            cin>>a;
            ans.pb(s);
            ans2.pb(a);
            cnt[a]++;
            if(cnt[a] == 1) x.insert(a);
        }
        if(s== "removeMin") {
            if(x.empty()) {
                ans.pb("insert");
                ans2.pb(0);
                ans.pb(s);
                ans2.pb(0);
            }
            else {
                int amin = *x.begin();
                ans.pb(s);
                ans2.pb(0);
                cnt[amin]--;
                if(cnt[amin]==0) x.erase(amin);
            }
        }
        if(s=="getMin") {
            cin >> a;
            if(x.empty()) {
                ans.pb("insert");
                ans2.pb(a);
                cnt[a]++;
                if(cnt[a] == 1) x.insert(a);
                ans.pb(s);
                ans2.pb(a);
            }
            else {
                while(1) {
                    if(x.empty() || *x.begin() > a) {
                        ans.pb("insert");
                        cnt[a]++;
                        if(cnt[a] == 1) x.insert(a);
                        ans2.pb(a);
                        ans.pb(s);
                        ans2.pb(a);
                        break;
                    }
                    else if(*x.begin() == a) {
                        ans.pb(s);
                        ans2.pb(a);
                        break;
                    }
                    else {
                        ans.pb("removeMin");
                        int amin = *x.begin();
                        ans2.pb(0);
                        cnt[amin]--;
                        if(cnt[amin]==0) x.erase(amin);
                    }
                }
            }
        }
    }
    printf("%d\n", (int)ans.size());
    forn(i,0,ans.size()) {
        printf("%s", ans[i].c_str());
        if(ans[i] == "removeMin") printf("\n");
        else printf(" %d\n", ans2[i]);
    }
}