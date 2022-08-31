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
#include <bitset>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef vector<vb> vvb;
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
int d[71000];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,s;
    cin>>n>>s;
    vpi a(n);
    vi bag(n);
    forn(i,0,n) cin>>a[i].first;
    forn(i,0,n) a[i].second = i;
    forn(i,0,n) bag[i] = a[i].first;
    sort(all(a));
    vi used(n,0);
    used[a.back().second] = 1;
    s-=a.back().first;
    if(s<0) {
        cout<<-1;
        return 0;
    }
    const int INF = 900000;
//    vi d(s+1, -1);
    forn(i,0,s+1) d[i] = -1;
    d[0] = INF;
    const int U = s+1;
    bitset<70001> curd;
    curd[0] = 1;
    forn(i,0,n) {
        
        if(bag[i] == 0) continue;
        if(i==a.back().second) {
            //d[i+1] = d[i];
            continue;
        }
        int bi = bag[i];
        auto curd2 = (curd << bi);
        auto dnew = curd2&(~curd);
        int ind = dnew._Find_first();
        while(ind != dnew.size()) {
            d[ind] = i;
            ind = dnew._Find_next(ind);
        }
        curd |= curd2;
//        for(int j = s; j>=bi; j--) {
//            if(d[j] <0 && d[j-bi]>=0) d[j] = i;
//        }
    }
    
    if(d[s] == -1) {
        cout<<-1;
        return 0;
    }
    else {
        
        int cur = d[s];
        int sum = s;
        while(1) {
            if(sum == 0) break;
            used[cur] = 1;
            sum -= bag[cur];
            if(sum == 0) break;
            cur = d[sum];
        }
        vi num(n,0);
        vi ch(n, -1);
        forn(i,0,n) {
            if(i==0) num[a[0].second] = a[0].first;
            else {
                if(used[a[i-1].second]) {
                    num[a[i].second] = a[i].first;//bag[a[i].second];
                }
                else {
                    num[a[i].second] = a[i].first-a[i-1].first;//bag[a[i].second] - bag[a[i-1].second];
                    ch[a[i].second] = a[i-1].second;
                }
            }
        }
        forn(i,0,n) {
            printf("%d ", num[i]);
            if(ch[i]>=0) printf("1 %d\n", ch[i]+1);
            else printf("0\n");
        }
    }
}