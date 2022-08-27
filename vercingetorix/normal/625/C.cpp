#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,k;
    ll ans = 0;
    cin >> n >>k;
    vvi t(n, vi(n));
    for(int x = (k-1)*n+1; x<=n*n; x++) {
        t[(x-1-(k-1)*n)/(n-k+1)][k-1+(x-1-(k-1)*n)%(n-k+1)] = x;
    }
    for(int x = 1; x<=(k-1)*n; x++) {
        t[(x-1)/(k-1)][(x-1)%(k-1)] = x;
    }
    
    for(int i=0; i<n; i++) ans+=t[i][k-1];
    cout<<ans<<endl;
    for(int i =0; i<n; i++) {
        for(int j=0;j<n;j++) {
            cout<<t[i][j]<<" ";
        }
        cout<<endl;
    }
}