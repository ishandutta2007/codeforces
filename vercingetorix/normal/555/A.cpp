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
    cin>>n>>k;
    //for(int i=0; i<n; i++) 
    int ans=0;
    int firstn;
    for(int i=0; i<k; i++) {
        int x;
        cin>>x;
        vi f(x);
        for(int j=0; j<x; j++) cin>>f[j];
        if(f[0]!=1) ans+=(x-1);
        else {
            int cur=0;
            while((cur<=x)&&(f[cur]==(cur+1))) cur++;
            firstn=cur;
            ans+=(x-cur);
        }
    }
    ans+=n-firstn;
    cout<<ans;
}