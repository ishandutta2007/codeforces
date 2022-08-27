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

long long gcd(long long a, long long b){
    if(a==0) return b;
    if(b==0) return a;
    if(a>b) return gcd(b, a%b);
    return gcd(a,b%a);
}

int main()
{
    #ifndef ONLINE_JUDGE  
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
    int n,m;
    cin>>n>>m;
    string s;
    string p;
    cin>>p;
    int l=p.length();
    int f=0;
    vi y(m);
    vb u(n, true);
    int curmax = 0;
    int ans =0;
    for(int i=0; i<m; i++) {
        cin>>y[i];
        y[i]--;
        if(y[i]>curmax) ans+=y[i]-curmax;
        curmax = y[i]+ l;
    }
    ans+=n-curmax;
    vi shift(n,0);
    for(int i=1; i<m; i++) shift[y[i]-y[i-1]] = 1;

    vi pf (l);
    pf[0] = 0;
    for (int k = 0, i = 1; i<l; ++i){
        while(k>0 && p[i] != p[k])
            k = pf[k-1];
        if (p[i] == p[k])
            k++;
        pf[i] = k;
    }
    int curl=l;
    while(curl>0){
        shift[l-curl]=0;
        curl=pf[curl-1];
    }
    for(int i=0; i<l; i++) {
       // cout<<pf[i]<<endl;
    }
    for(int i=0; i<l; i++) {
        if(shift[i]) {
            cout<<0;
            return 0;
        }
    }
    ll am=1;
    for(int i=0; i<ans;i++) {
        am=(am*26)%mod;
    }
    cout<<am;
}