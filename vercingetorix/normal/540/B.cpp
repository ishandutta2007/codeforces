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

int main()
{
    #ifndef ONLINE_JUDGE  
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
    int n,k,p,x,y;
    cin>>n>>k>>p>>x>>y;
    vi a(k);
    vi ans;
    int bm=0;
    int sum=0;
    for(int i=0; i<k; i++) {
        cin>>a[i];
        if(a[i]>=y) bm++;
        sum+=a[i];
    }
    while(bm<(n+1)/2) {
        k++;
        sum+=y;
        bm++;
        ans.pb(y);
    }
    if(k>n) {
        cout<<-1;
        return 0;
    }
    while(k<n) {
        sum++;
        k++;
        ans.pb(1);
    }
    if(sum>x) {
        cout<<-1;
        return 0;
    }
    for(int i=0; i<ans.size(); i++) {
        cout<<ans[i]<<" ";
    }
    
}