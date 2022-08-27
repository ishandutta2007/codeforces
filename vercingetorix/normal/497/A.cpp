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
    int n,m;
    int ans=0;
    cin>>n>>m;
    if(n==1){
        cout<<0;
        return 0;
    }
    char t[1001][1001];
    vb br(n+1, false);
    for(int i=0;i<n;i++){
        for(int j=0; j<m; j++){
            cin>>t[i][j];
        }
    }
    for(int j=0; j<m; j++){
        bool f=true;
       for(int i=1; i<n; i++){
           if((t[i][j]<t[i-1][j])&&(br[i]==false)){
               ans++; f=false;
               break;
           }
        }
        if(f) for(int i=1; i<n; i++) if(t[i][j]>t[i-1][j]) br[i]=true;
    }
    cout<<ans;
    
}