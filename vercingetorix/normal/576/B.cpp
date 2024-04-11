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
    //ll ans = 0;
    cin >> n;
    vi a(n);
    forn(i,0,n) {
        cin>>a[i];
        a[i]--;
    }
    int minl = n+1;
    int startl=0;
    vb used(n,false);
    for(int i=0; i<n; i++) {
        if(!used[i]) {
            int cur = a[i];
            int curl = 1;
            used[i]=true;
            while(cur != i) {
                used[cur]=true;
                curl++;
                cur=a[cur];
            }
            if(curl<minl) {
                startl =i;
                minl=curl;
            }
        }
    }
    forn(i,0,n) used[i] = false;
    if(minl>2) {
        cout<<"NO";
        return 0;
    }
    if(minl==1) {
        cout<<"YES"<<endl;
        forn(i,0,n) {
            if(i!=startl) cout<<i+1<<" "<<startl+1<<endl;
        }
        return 0;
    }
    //minl =2
    int u = startl;
    int v = a[startl];
    used[v]=true;
    used[u]=true;
    vpi ans;
    ans.pb(mp(v+1,u+1));
    for(int i=0; i<n; i++) {
        if(!used[i]) {
            int cur = a[i];
            int curl = 1;
            used[i]=true;
            while(cur != i) {
                used[cur]=true;
                if(curl&1) ans.pb(mp(u+1, cur+1));
                else ans.pb(mp(v+1, cur+1));
                curl++;
                cur=a[cur];
            }
            ans.pb(mp(v+1, i+1));
            if(curl&1) {
                cout<<"NO";
                return 0;
            }
        }
    }
    cout<<"YES"<<endl;
    for(auto x:ans) {
        cout<<x.first<<" "<<x.second<<endl;
    }
   // cout<<ans;
}