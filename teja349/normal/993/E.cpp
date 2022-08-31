//teja349
#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <iomanip> 
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx
//cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val

using namespace std;
#define f(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) f(i,0,n)
#define fd(i,a,b) for(i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define vi vector< int >
#define vl vector< ll >
#define ss second
#define ff first
#define ll long long
#define pii pair< int,int >
#define pll pair< ll,ll >
#define sz(a) a.size()
#define inf (1000*1000*1000+5)
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod (1000*1000*1000+7)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >

//std::ios::sync_with_stdio(false);   


/*
Copied from rajat1603 (fft and multiply with bit inverse(inplace precomputation))
base class taken from rajat
TESTED with: VFMUL -------(SPOJ)
             POLYMUL ------(SPOJ)
             Thief in shop  ---(CODEFORCES)

*/

const long double pi = 4.0 * atan(1.0);
//const ll N = 2e5 + 5;
ll P = 1 << 19;
ll K = 0;
struct base{
    double x , y;
    base(){
        x = 0;
        y = 0;
    }
    base(double a){
        x = a;
        y = 0;
    }
    base(double a , double b){
        x = a;
        y = b;
    }
    base conj(){
        return base(x , -y);
    }
    base operator = (const base &o){
        x = o.x;
        y = o.y;
        return *this;
    }
    base operator + (const base &o) const {
        return base(x + o.x , y + o.y);
    }
    base operator - (const base &o) const {
        return base(x - o.x , y - o.y);
    }
    base operator * (const base &o) const {
        return base(x * o.x - y * o.y , y * o.x + x * o.y);
    }
    base operator * (const double num) const {
        return base(x * num , y * num);
    }
    base operator / (const double num) const {
        return base(x / num , y / num);
    }

};

// initializations
ll rev[(1<<19)+3];
base fa[(1<<19)+3],fb[(1<<19)+3];
ll res[(1<<19)+3]; 

// bit inverse permutation mathod
void pre(){
    ll res;
    for(ll i = 0 ; i < P ; ++i){
        res = 0;
        for(ll j = 0 ; j < K ; ++j){
            if((i >> j) & 1){
                res |= 1 << (K - j - 1);
            }
        }
        rev[i] = res;
    }
}

// fft works 

void fft(base a[] , bool inv){
    for(ll i = 0 ; i < P ; ++i){
        if(rev[i] > i){
            swap(a[i] , a[rev[i]]);
        }
    }
    for(ll size = 2 ; size <= P ; size <<= 1){
        ll m = size >> 1;
        base w(cos(2 * pi / size) , sin(2 * pi / size) * (inv ? -1 : 1));
        for(ll i = 0 ; i < P ; i += size){
            base cur(1 , 0);
            for(ll j = 0 ; j < m ; ++j){
                base v = a[i + j];
                base u = a[i + j + m] * cur;
                a[i + j] = v + u;
                a[i + j + m] = v - u;
                cur = cur * w;
            }
        }
    }
}


// call this to multiply two polynomials result is stored in res
void multiply (base a[],base b[]) {
    pre();
	fft (a, false),  fft (b, false);
	for (ll i=0; i<P; ++i){
		a[i] =a[i]*b[i];
	}
	fft (a, true);
	for (ll i=0; i<P; ++i){
		res[i] = (ll)((a[i].x)/P + 0.5);
	}
}

/*
    STEPS TO FOLLOW 
    1. SET P and K as required
    2 check initializations and rock
*/

ll a[212345],st[212345],en[212345],ans[212345];
vl vec;
int main(){
    std::ios::sync_with_stdio(false);
    ll n,x;
    cin>>n>>x;
    ll i;

    rep(i,n){
        cin>>a[i];
    }
    vec.pb(-1);
    rep(i,n){
        if(a[i]<x)
            vec.pb(i);
    }
    vec.pb(n);
    ll tot=vec.size();
    tot-=2;
    f(i,1,vec.size()-1){

        st[i-1]=vec[i]-vec[i-1];
        en[i-1]=vec[i+1]-vec[i];
    }
    ll elems;
    ll wowo=0;
    f(i,1,vec.size()){
        elems=vec[i]-vec[i-1]-1;
        wowo+=elems*(elems+1)/2;
    }
    K=0;
    while((1<<K)<tot+3) K++;
    K++;
    P=(1<<K);
    rep(i,tot){
        fa[i]=base(st[i],0);
        fb[tot-i-1]=base(en[i],0);
    }
    multiply(fa,fb);
    rep(i,tot){
        ans[tot-i]=res[i];
    }
    ans[0]=wowo;
    rep(i,n+1){
        cout<<ans[i]<<" ";
    }

    return 0;  
    
}