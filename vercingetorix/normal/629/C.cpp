#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <set>
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
typedef std::vector<std::vector<ll> > vvll;
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
    int n,m;
    ll ans = 0;
    scanf("%d %d\n", &n, &m);
    string s;
    getline(cin, s);
    int l = s.size();
    int lprev=0, rprev=0, totdiff;
    int diff=0;
    for(int i =0; i<l; i++) {
        if(s[i]==')') diff++;
        else diff--;
        lprev=max(lprev, diff);
    }
    totdiff = diff;
    diff=0;
    for(int i =l-1; i>=0; i--) {
        if(s[i]=='(') diff++;
        else diff--;
        rprev=max(rprev, diff);
    }
    vvll lp(n-m+1, vll(n-m+1, 0));
    lp[0][0] = 1;
    for(int i =1; i<=n-m; i++) {
        for(int j= 0; j<=n-m; j++) {
            if(j>0) lp[i][j] += lp[i-1][j-1];
            if(j<n-m) lp[i][j] += lp[i-1][j+1];
            lp[i][j]=lp[i][j]%mod;
        }
    }
    for(int i =0; i<=n-m; i++) {
        for(int j=0; j<=n-m; j++) {
            if ((j>=lprev)&&(j-totdiff >=rprev)&&(j-totdiff<=n-m)) {
                ans=(ans+lp[i][j]*lp[n-m-i][j-totdiff])%mod;
            }
        }
    }
    
    
    cout<<ans;
}