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
    int n;
    scanf("%d", &n);
    vi a(n);
    vi b(n);

    forn(i,0,n) scanf("%d", &a[i]);
    forn(i,0,n) scanf("%d", &b[i]);
    vll s(n);
    s[n-1] = 0;
    vector<pair<double, int>> generated_events(n);
    set<pair<double,int>> events;
    set<int> lines;
    lines.insert(n-1);
    for (int cur = n-2; cur >= 0; cur--) {
        while(events.size()>0 && (events.begin())->first <= b[cur]) {
            int del = events.begin()->second;
            auto x = lines.find(del);
            auto next = x;
            ++next;
            if(x != lines.begin() && next != lines.end()) {
                auto prev = x;
                --prev;
                events.erase(generated_events[del]);
                generated_events[*prev] = mp((double)(s[*prev]-s[*next])/(a[*next]-a[*prev]), *next);
                events.erase(events.begin());
                events.insert(generated_events[*prev]);
            }
            else if (x != lines.begin()) {
                auto prev = x;
                --prev;
                events.erase(events.begin());
                //events.erase(generated_events[del]);
            }
            else {
                
            }

            lines.erase(x);
        }

        s[cur] = (ll)a[*(lines.rbegin())]*(ll)b[cur] + s[*(lines.rbegin())];
        int next = *(lines.begin());
        lines.insert(cur);
        generated_events[cur] = mp((double)(s[cur]-s[next])/(a[next]-a[cur]), next);
        events.insert(generated_events[cur]);
    }
    cout<<s[0];
  //  forn(i,0,n) cout<<s[i]<<" ";
}