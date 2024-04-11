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
    vb a(n);
    char c;
    fo(i,0,n) {
        cin>>c;
        if(c=='.') a[i]=false;
        else a[i]=true;
    }
    bool f=false;
    fo(i,0,n-4) {
        fo(j, 1, (n-1-i)/4+1) {
            if(a[i]&&a[i+j]&&a[i+2*j]&&a[i+3*j]&&a[i+4*j]) f=true;
        }
    }
    if(f) cout<<"yes";
    else cout<<"no";
}