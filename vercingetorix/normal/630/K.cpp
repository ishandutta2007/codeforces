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
typedef std::vector<std::vector<bool> > vvb;
typedef std::vector<std::pair<int, int> > vpi;
typedef std::pair<int, int> pi;

long long mod=1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back
#define mp make_pair

double pow(double k, int n) {
    if (n==0) return 1;
    if(n==1) return k;
    double x = pow(k, n/2);
    return x*x*pow(k, n%2);
}

long long cnk(ll n, ll k) {
    ll ans = 1;
    for(int i =0; i < k; i++) {
        if (ans%(i+1) == 0) ans = ((ans)/(i+1)) * (n-i);
        else if ((n-i)%(i+1) == 0) ans = ((n-i)/(i+1)) * (ans);
        else ans = ((ans)*(n-i)) / (i+1);
    }
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ll n,t;
    ll ans = 0;
    cin>>n;
    cout << n-n/2 -n/3-n/5-n/7+n/6+n/10+n/14+n/15+n/21+n/35-n/30-n/42-n/70-n/105+n/210;

    
    //cout<<ans;
}