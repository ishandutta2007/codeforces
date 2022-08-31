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
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef std::vector<std::pair<int, int> > vpi;
typedef std::pair<int, int> pi;

//long long mod=1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back
#define mp make_pair

ll d[2][504][504];

int main()
{
    #ifndef ONLINE_JUDGE  
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
    int n,m,b;
    
    ll mod;
    cin >> n>>m>>b>>mod;
    vi a(n+1);
    for(int i=0; i<n; i++) {
        cin>>a[i+1];
    }
    for(int i=0; i<=n; i++) for(int j=0; j<=b;j++) {
        d[1][i][j]=0;
    }
    d[1][1][0]=1;
    int cur=1;
    int prev=0;
    for(int p=1; p<=m; p++) {
        cur=1-cur;
        prev=1-prev;
        for(int i=1; i<=n; i++) for(int j=0; j<=b;j++) d[cur][i][j]=0;
        for(int i=1; i<=n; i++) {
            for(int j=0; j<=b-a[i]; j++) {
                d[cur][i][j+a[i]]+=d[prev][i][j];
            }
            for(int j=0; j<=b; j++) {
                d[prev][i+1][j]+=d[prev][i][j];
            }
        }
        for(int i=1; i<=n; i++) for(int j=0; j<=b;j++) d[cur][i][j]=d[cur][i][j]%mod;
    }
    ll ans=0;
    for(int i=1; i<=n; i++) for(int j=0; j<=b;j++) ans+=d[cur][i][j];
    cout<< ans%mod;
}