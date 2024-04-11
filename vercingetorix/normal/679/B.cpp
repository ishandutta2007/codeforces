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

pll go(ll m) {
    ll cur = 1;
    ll cur3 = 1;
    ll cur13 = 8;
    ll h = 0;
    ll num = 0;
    vll what;
    while(1) {
        while (h + cur3 >= cur13) {
            if(cur3>m) break;
            cur++;
            cur3=cur13;
            cur13 = (cur+1)*(cur+1)*(cur+1);
        }
        if(h + cur3 > m) break;
        h+=cur3;
        what.pb(cur3);
        num++;
    }
    vll ch(num+1,0);
    ll sum = 0;
    forn(i,0,num) {
        sum+=what[i];
        ch[i+1] = sum;
    }
    cur = 1;
    while(cur*cur*cur <= m) cur++;
    //int step = h-1;
    ll left = m;
    ll ans = 0;
    deque<ll> revans;
    for(int step = num-1; step>=0; step--) {
        //while(ch[step] + cur*cur*cur > left || ch[step] + cur*cur*cur >= (cur+1)*(cur+1)*(cur+1)) cur--;
        cur++;
        while(1) {
            cur--;
            if(ch[step] + cur*cur*cur > left) continue;
            ll cum = ch[step]+cur*cur*cur;
            bool f = false;
            forn(i,0,revans.size()) {
                cum += revans[i]*revans[i]*revans[i];
                ll ra3 = (revans[i]+1)*(revans[i]+1)*(revans[i]+1);
                if(cum >= ra3) {
                    f=true;
                    break;
                }
            }
            if(!f) break;
        }
        revans.push_front(cur);
        cur3=cur*cur*cur;
        left-=cur3;
        ans+=cur3;
    }
    
    
    return mp (num, ans);
    
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ll m;
    cin>>m;
    pll x= go(m);
    cout<<x.first<<" "<<x.second;
    
}