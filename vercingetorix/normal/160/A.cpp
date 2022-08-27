#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <set>
#include <list>
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
    int n,m,k;
    ll ans = 0;
    cin >> n;
    vi a(n);
    int sum=0;
    for(int i =0; i<n; i++) cin>>a[i];
    for(int i =0; i<n; i++) sum+=a[i];
    sort(all(a));
    reverse(all(a));
    int cur=0;
    int cs= 0;
    while(cs*2<=sum) {
        cs+=a[cur];
        cur++;
    }
    cout<<cur;
    
    
    
    //   cout<<ans;
}