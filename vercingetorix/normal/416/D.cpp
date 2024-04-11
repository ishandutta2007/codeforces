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
    vi resp;
    forn(i,0,n) {
        scanf("%d", &a[i]);
    }
    ll cur = 0;
    int ans =0;
    while(cur<n) {
        ll cur1=cur;
        while(cur1<n && a[cur1] == -1) cur1++;
        ll cur2 = cur1+1;
        while(cur2<n && a[cur2] == -1) cur2++;
        if(cur2>=n) {
            ans++;
            break;
        }
        ll diff = a[cur2] - a[cur1];
        if(diff%(cur2-cur1) != 0) {
            ans++;
            cur = cur2;
            continue;
        }
        ll step = diff / (cur2-cur1);
        if (((ll)a[cur1] - step* (cur1-cur) )<=0) {
            ans++;
            cur = cur2;
            continue;
        }
        else {
            ll pr = a[cur2];
            ll cur3 = cur2;
            while(cur3<n && pr>0 && (a[cur3] == pr || a[cur3] == -1)) {
                pr+=step;
                cur3++;
            }
            ans++;
            cur=cur3;
        }
    }
    cout<<ans;

    
}