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

map<ll, ll> F;
ll M;
ll f(ll n) {
    if (F.count(n)) return F[n];
    ll k=n/2;
    if (n%2==0) { // n=2*k
        return F[n] = (f(k)*f(k) + f(k-1)*f(k-1)) % M;
    } else { // n=2*k+1
        return F[n] = (f(k)*f(k+1) + f(k-1)*f(k)) % M;
    }
}

ll p2modM(ll n){
    if(n==0) return 1%M;
    ll x=p2modM(n/2);
    if(n%2==0) return (x*x)%M;
    else return (2*x*x)%M;
}

int main()
{
    #ifndef ONLINE_JUDGE  
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
    ll n,k,l,m;
    cin>>n>>k>>l>>m;
    M=m;
    F[0]=1;
    F[1]=1;
    //cout<<f(1)<<endl;
    //cout<<f(2)<<endl;
    //cout<<f(3)<<endl;
   // cout<<f(4)<<endl;
    
    //for(int i=0; i<n; i++) 
    ll ans=1;
    ll n0, n1;
    n0=f(n+1);
    n1=(p2modM(n)+m-n0)%m;
    //TODO
    fo(i,0,l){
        if((k%2)==0) ans=(ans*n0)%m;
        else ans=(ans*n1)%m;
        k/=2;
    }
    if(k>0) ans=0;
    cout<<ans%m;
}