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
typedef std::vector<std::vector<bool> > vvb;
typedef std::vector<std::pair<int, int> > vpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

long long mod=1000000007;

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
    int n,m,k;
    //string s;
    ll ans = 0;
    cin >> n>>m;
    vector<vector<pair<int,string>>> user(m+1);
    forn(i,0,n) {
        string s;
        int reg, ball;
        cin>>s>>reg>>ball;
        user[reg].pb(mp(ball,s));
    }
    forn(i,1,m+1) {
        sort(all(user[i]));
        reverse(all(user[i]));
        user[i].pb(mp(-1,"hoang"));
        if(user[i][1].first==user[i][2].first) cout<<"?"<<endl;
        else cout<<user[i][0].second<<" "<<user[i][1].second<<endl;
    }

    
    // cout<<ans;
}