#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
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
typedef std::pair<int, int> pi;

long long mod=1000000007;


#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back
#define mp make_pair

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ll d,n, m;
    cin >> d>>n>>m;
    vll x(m+2), p(m+2);
    vpi pos;
    vpi cost;
    ll ans = 0;
    for(int i=1; i<=m; i++) {
        cin >> x[i] >> p[i];
        pos.pb(mp(x[i], i));
        cost.pb(mp(p[i], i));
    }
    pos.pb(mp(0, 0));
    pos.pb(mp(d, m+1));
    sort(all(pos));
    sort(all(cost));
    reverse(all(cost));
    vi left(m+2), right(m+2);
    vi distleft(m+2), distright(m+2);
    for(int i=1; i<=m; i++) {
        left[pos[i].second] = pos[i-1].second;
        right[pos[i].second] = pos[i+1].second;
        distleft[pos[i].second] = pos[i].first - pos[i-1].first;
        distright[pos[i].second] = pos[i+1].first - pos[i].first;
    }
    for (auto a : cost) {
        int c = a.second;
        int cl = left[c];
        int cr= right[c];
        ll dl = distleft[c];
        ll dr= distright[c];
        if ((dl>n) || (dr>n)) {
            cout<<-1;
            return 0 ;
        }
        ans += p[c] * max(0ll, dl+dr-n);
        distleft[cr]=min(n, dl+dr);
        distright[cl]=min(n, dl+dr);;
        left[cr]=cl;
        right[cl]=cr;
    }
    cout<<ans;

}