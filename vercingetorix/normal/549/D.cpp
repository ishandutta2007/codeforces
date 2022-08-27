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

long long mod=1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back
#define mp make_pair
char p[120][120];
int main()
{
    #ifndef ONLINE_JUDGE  
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
    int n,m;
    cin>>n>>m;
    for(int i=0; i<n;i++) {
        for(int j=0; j<m;j++) 
            cin>>p[i][j];
    }
    int ans=0;
    vi rc(n, 0);
    for(int j=m-1; j>=0; j--) {
        for(int i=n-1; i>=0; i--) {
            char c=p[i][j];
            int need;
            if(c=='W') need = 1;
            else need = -1;
            if(rc[i]==need) continue;
            else {
                ans++;
                for(int k=0; k<=i; k++) rc[k] += need-rc[i];
            }
        }
    }
    cout<<ans;
}