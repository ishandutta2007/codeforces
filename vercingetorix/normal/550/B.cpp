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
    int n,l,r,x;
    cin >>n>>l>>r>>x;
    vi a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    int deg=0;
    int p2=1;
    int ans=0;
    for(;deg<n; deg++) p2*=2;
    for(int i=1; i<p2; i++) {
        int bit=i;
        vi b;
        ll sum=0;
        for(int j=0; j<n; j++) {
            if(bit%2) {
                b.pb(a[j]);
                sum+=a[j];
            }
            bit/=2;
        }
        sort(all(b));
        int y=b.size();
        if((sum>=l)&&(sum<=r)&&(y>=2)&&((b[y-1]-b[0])>=x)) ans++;
        
    }
    cout<<ans;
}