#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <set>
#include <map>
#include <unordered_map>
#include <stdio.h>
#include <cstdlib>

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
int p[120][120];
int main()
{
    #ifndef ONLINE_JUDGE  
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
    int n;
    cin>>n;
    char c;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++){
           cin>>c;
           p[i][j]=c-'0';
        }
    }
    vi a(n+1);
    for(int i=1; i<=n; i++) cin>>a[i];
    vi cur(n+1, 0);
    vi ans;
    for(int jk=0; jk<100; jk++) {
        for(int i=1; i<=n; i++) {
            if(a[i]==cur[i]) {
                ans.pb(i);
                for(int j=1; j<=n; j++) {
                    if(p[i][j]==1) cur[j]++;
                }
            }
        }
    }
    cout<<ans.size()<<endl;
    for(int i=0; i<ans.size(); i++) {
        cout<<ans[i]<<endl;
    }
    
    
}