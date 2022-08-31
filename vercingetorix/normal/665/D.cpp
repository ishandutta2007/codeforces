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
#include <unordered_map>
#include <map>
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
    const int LIMIT = 2000000;
    vb isp(LIMIT+1, true);
    vi mindiv(LIMIT+1, 0);
    forn(i,0,LIMIT+1) mindiv[i]=i;
    int upbound = (int)sqrt((double)LIMIT);
    vi p;
    for (int m = 2; m <= upbound; m++) {
        if (isp[m]) {
            p.pb(m);
            for (int k = m * m; k <= LIMIT; k += m) {
                isp[k] = false;
                mindiv[k]=min(mindiv[k], m);
            }
        }
    }
    for(int m = upbound+1; m<=LIMIT; m++) {
        if (isp[m]) {
            p.pb(m);
        }
    }
    int n;
    cin>>n;
    vi a(n);
    int cnt1=0;
    int cnt2=0;
    forn(i,0,n) {
        cin>>a[i];
        if(a[i]==1) cnt1++;
        if(a[i]==2) cnt2++;
    }
    if(cnt1>=2) {
        int cur = -1;
        forn(i,0,n) {
            if(a[i]==1) continue;
            if(isp[a[i]+1]) cur=a[i];
        }
        int x = 0;
        if(cur>0) x=1;
        cout<<cnt1+x<<endl;
        forn(i,0,cnt1) cout<<"1 ";
        if(x) cout<<cur;
        return 0;
    }
    forn(i,0,n) forn(j,i+1,n) {
        if(isp[a[i]+a[j]]) {
            cout<<2<<endl<<a[i]<<" "<<a[j];
            return 0;
        }
    }
    cout<<1<<endl<<a[0];
    return 0;
    
}