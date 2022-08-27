#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef std::vector<std::vector<bool> > vvb;
typedef std::vector<std::pair<int, int> > vpi;
typedef std::vector<std::pair<ll, ll> > vpll;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;

long long mod=1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back
#define mp make_pair

bool comp(pll x, pll y) {
    if(x.first != y.first) return false;
    if(x.second < 0) return true;
    if(y.second < 0) return true;
    return(x.second == y.second);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    ll ans = 0;
    //cin >> n;
    scanf("%d %d\n", &n,&m);
    char hlam, c;
    int x;
    vpll t;
    vpll s;
    for(int i = 0; i< n; i++) {
        scanf("%d%c%c", &x, &hlam, &c);
        if ((t.size() == 0 ) || (t.back().first != (int)(c - 'a'))){
            t.pb(mp((int)c - 'a', x));
        }
        else t.back().second += x;
    }
    for(int i = 0; i< m; i++) {
        scanf("%d%c%c", &x, &hlam, &c);
        if ((s.size() == 0 ) || (s.back().first != (int)(c - 'a'))){
            s.pb(mp((int)c - 'a', x));
        }
        else s.back().second += x;
    }
    n = t.size();
    m= s.size();
    ll sf= s.front().second;
    ll sb= s.back().second;
    s.front().second=-1;
    s.back().second=-1;
    s.pb(mp(777, 141));
    for(auto x : t) s.pb(x);
    vector<int> pi (s.size());
    for (int i=1; i<s.size(); ++i) {
        int j = pi[i-1];
        while (j > 0 && !comp(s[i],s[j]))
            j = pi[j-1];
        if (comp(s[i], s[j]))  ++j;
        pi[i] = j;
    }
    for(int i = m+1; i<s.size(); i++) {
        if(pi[i]==m) {
            if(m == 1) {
                if(s[i].second >= sf) ans += s[i].second-sf+1;
            }
            else {
                if((s[i].second >= sb) && (s[i-m+1].second >= sf)) ans++;
            }
        }
    }
    

    
    cout<<ans;
}