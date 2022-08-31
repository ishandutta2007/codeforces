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
    int n,m,k;
    //ll ans = 0;
    //cin >> n>>m>>k;
    scanf("%d %d %d\n", &n,&m,&k);
    vi c(k), a(k), col(k);
    vvi ans(n, vi(m,0));
    for(int i =0; i<k; i++) {
        scanf("%d %d %d\n", &c[i],&a[i],&col[i]);
        a[i]--;
    }
    vb ru(n, false);
    vb cu(m, false);
    for(int i =k-1; i>=0; i--) {
        if(c[i]==1) {
            if(ru[a[i]]) continue;
            ru[a[i]] = true;
            for(int j=0; j<m; j++) {
                if(!cu[j]) ans[a[i]][j] = col[i];
            }
        }
        if(c[i]==2) {
            if(cu[a[i]]) continue;
            cu[a[i]] = true;
            for(int j=0; j<n; j++) {
                if(!ru[j]) ans[j][a[i]] = col[i];
            }
        }
    }
    
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m;j++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}