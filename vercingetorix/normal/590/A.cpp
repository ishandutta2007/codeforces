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
    int n,m;
    int jd=0;
    cin>>n;
    vi a(n);
    for(int i =0; i<n; i++) cin>>a[i];
    vb b(n, true);
    for(int i =1; i<n-1; i++) {
        if((a[i]!=a[i-1])&&(a[i]!=a[i+1])) b[i]=false;
    }
    //vi c(n);
    int cur=1;
    int maxt= 0;
    while (cur<n) {
        if(b[cur]){
            cur++; continue;
        }
        int l  =cur;
        while(!b[cur]) cur++;
        int r = cur;
        if((r-l+1)/2 > maxt) maxt = (r-l+1)/2;
        if((r-l)%2==1) {
            for(int i =l; i<r; i++) a[i]=a[l-1];
        }
        else {
            for(int i=l; i<(r+l)/2; i++) a[i] = a[l-1];
            for(int i=(r+l)/2; i<r; i++) a[i] = a[r];
        }
    }
    cout<<maxt<<endl;
    for(int i =0; i<n; i++) cout<<a[i]<<" ";

    
}