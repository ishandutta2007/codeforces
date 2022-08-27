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
vll a;
ll n,m;
bool go(ll t) {
    vll b=a;
    int curbox=n-1;
    fo(i, 0, m) {
        while((curbox>=0)&&(b[curbox]==0)) curbox--;
        ll power=t-curbox;
        while((curbox>=0)&&(power>0)) {
            int hod=min(b[curbox], power);
            power-=hod;
            b[curbox]-=hod;
            while((curbox>=0)&&(b[curbox]==0)) curbox--;
        }
    }
    return (curbox==-1);
}
int main()
{
    #ifndef ONLINE_JUDGE  
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
    
    cin>>n>>m;
    //for(int i=0; i<n; i++) 
    a.resize(n);
    ll sum=0;
    fo(i,0,n) {
        cin>>a[i];
        sum+=a[i];
    }
    ll tl=0;
    ll tr=sum/m + n; 
    while(tr-tl>1) {
       ll tm=(tr+tl)/2;
       if(go(tm)) {
           tr=tm;
       }
       else {
           tl=tm;
       }
    }
    if(go(tl)) cout<<tl+1;
    else cout<<tr+1;
}