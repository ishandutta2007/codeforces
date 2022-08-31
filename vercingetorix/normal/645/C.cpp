#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <queue>
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

    scanf("%d %d\n", &n, &k);
        int ans = n;
    char c;
    vb a(n,true);
    forn(i,0,n) {
        scanf("%c", &c);
        if(c=='1') a[i]=false;
    }
    deque<int> rooms;
    int curpt = 0;
    while(rooms.size() < k+1) {
        while(!a[curpt]) curpt++;
        rooms.pb(curpt);
        curpt++;
    }
    while(1) {
        int midroom = (rooms.front() + rooms.back() + 1)/2;
        auto x = lower_bound(rooms.begin(), rooms.end(), midroom);
        auto y = x;
        y--;
        ans = min(ans, *x - rooms.front());
        ans = min(ans, rooms.back() - *y);
        rooms.pop_front();
        while ((curpt < n) && (!a[curpt])) curpt++;
        if(curpt>=n) break;
        rooms.pb(curpt);
        curpt++;
    }
    cout<<ans;
    //cout<<ans;
}