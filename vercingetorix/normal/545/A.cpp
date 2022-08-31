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

long long mod=1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back
#define mp make_pair

int res[100][100];

int main()
{
    #ifndef ONLINE_JUDGE  
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
    int ans = 0;
    vi a;
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>res[i][j];
        
        
    for(int i=0;i<n;i++) {
        bool f = true;
        for(int j=0;j<n;j++) if((res[i][j]==1)||(res[i][j]==3)) f=false;
        if(f) {
            ans++;
            a.pb(i+1);
        }
    }
    cout<<ans<<endl;
    for(int i=0; i<ans; i++) cout<<a[i]<<" ";


}