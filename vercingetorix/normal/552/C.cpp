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
    ll w,m;
    cin>>w>>m;
    //for(int i=0; i<n; i++) 
    if(w==2){
        cout<<"YES";
        return 0;
    }
    else {
        for(int i=0; i<=100; i++) {
            if(m==0) break;
            if(m%w==0) m/=w;
            else if(m%w==1) m=(m-1)/w;
            else if(m%w==w-1) m=(m+1)/w;
        }
    }
    if(m==0) cout<<"YES";
    else cout<<"NO";
    
    
}