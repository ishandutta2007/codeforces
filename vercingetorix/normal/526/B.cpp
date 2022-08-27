#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <set>
#include <map>
#include <deque>
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
#define fo(a, b, c) for(int a = b; a < c; a++)

#define pb push_back
#define mp make_pair

int main()
{
    #ifndef ONLINE_JUDGE  
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
    int n,k;
    cin>>n;
    //for(int i=0; i<n; i++) 
    int p2=1;
    fo(i,0,n) p2*=2;
    p2*=2;
    vi a(p2);
    fo(i, 2, p2) cin>>a[i];
    int ans=0;
    for(int i=p2-1; i>1; i-=2) {
        if(i<p2/2) {
            a[i]+=a[2*i];
            a[i-1]+=a[2*i-2];
        }
        ans+=abs(a[i]-a[i-1]);
        a[i]=max(a[i],a[i-1]);
        a[i-1]=a[i];
    }
    cout<<ans;
}