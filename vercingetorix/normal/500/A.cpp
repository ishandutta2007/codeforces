#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <stdio.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;

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
    int n,t;
    int ans=0;
    cin>>n>>t;
    vb m(n+1,false);
    m[1]=true;
    for(int i=1; i<=n-1; i++){
        int x;
        cin>>x;
        if(m[i]) m[i+x]=true;
    }

    if(m[t]) cout<<"YES";
    else cout<<"NO";
    
}