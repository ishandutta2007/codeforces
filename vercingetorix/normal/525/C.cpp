#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <deque>
#include <map>
#include <stdio.h>
#include <sstream>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;

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
    int n;
    cin>>n;
    vi a(n);
    ll ans=0;
    for(int i=0; i<n; i++) cin>>a[i];
    sort(all(a));
    int cur=n-1;
    vll pairs;
    while(cur>=1) {
        if(a[cur-1]<a[cur]-1) cur--;
        else {
            pairs.pb(a[cur-1]);
            cur-=2;
        }
    }
    //cout<<pairs.size();
    //return 0;
    for(int i=0; i<(pairs.size()-1); i+=2) {
        if(i+1>=pairs.size()) break;
        ans+=pairs[i]*pairs[i+1];
    }
    cout<<ans;
}