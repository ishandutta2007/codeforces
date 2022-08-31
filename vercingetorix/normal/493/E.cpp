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
    ll t,a,b;
    cin>>t>>a>>b;
    if(a==t){
        if(a!=b) cout<<0;
        else if(t==1) cout<<"inf";
        else cout<<2;
        return 0;
    }
    if(t>a) {
        if(a==b) cout<<1;
        else cout<<0;
        return 0;
    }
    if(b<a) {
        cout<<0; return 0;
    }
    if(b==a) {
        cout<<1; return 0;
    }
    // t<a<b 
    if(((b-a)%(a-t))!=0){
        cout<<0;
        return 0;
    }
    ll a1=(b-a)/(a-t);
    ll a0=a-a1*t;
    if(((double)a>=(double)a1*(double)t)&&(a0>=0)) {
        cout<<1; return 0;
    }
    ll b0=(-a0)/(t*a);
    if((-a0)%(t*a)!=0) b0++;
    if(b0*(a+t)<=a1) {
        cout<<1;
        return 0;
    }
    ll b1=(b0*(a+t)-a1)/(a*t);
    if((b0*(a+t)-a1)%(a*t)!=0) b1++;
    do{
        ll u=b1*(a+t)-b0;
        if(u<0) {
            cout<<1;
            return 0;
        }
        ll bnew=u/(a*t);
        if(u%(a*t)!=0) bnew++;
        b0=b1;
        b1=bnew;
    }
    while(b1<b0);
    cout<<0;
}