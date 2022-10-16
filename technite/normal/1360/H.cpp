//template start//
#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define F first
#define S second
#define pb push_back
#define forn(i, n) for(int i = 0; i < n; ++i)
#define forl(i, n) for(long long i=0;i<n;++i)
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vi>
#define vvl vector<vl>
#define vpi vector<pi>
#define vpl vector<pl>
#define pi pair<int,int>
#define pl pair<ll,ll>
#define all(x) x.begin(),x.end()
typedef long double ld; 
typedef double dd;
typedef long long ll;
const int MOD = 998244353; // = (119<<23)+1
const ll INF = 1e18; 
const ld PI = 4*atan((ld)1); 
template<typename T>
void printvector(vector<T>& v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<' ';
    }
    cout<<"\n";
}
template<typename T>
void printarray(T a[])
{
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<" "; 
    }
    cout<<"\n";
}
 
void printpairs(vector<pair<int,int>>& v){
    for(int i=0;i<v.size();i++){
        cout<<v[i].F<<','<<v[i].S<<'|';
    }
    cout<<endl;
}
 
void print2d(vector<vector<int>>&v){
    for(int i=0;i<v.size();i++){
        printvector(v[i]);
    }
}
// checks if a number is a perfect square in almost O(1) time
long long sqroot(long long n){
    long double N = n;
    N = sqrtl(N);
    long long sq = N-2;
    sq = max(sq,0LL);
    while(sq*sq<n){
        sq++;
    } 
    if((sq*sq)==n)
        return sq;
    return -1;
}
//exponent in log(m) time
ll exp(ll n, ll m, ll md){
    ll a = 1;
    while (m > 0){
        if (m&1) a = (a * n%md) % md;
        m /= 2;
        n = (n*n) % md;
    }
    return a % md;
}
#define TT int T;cin>>T;for(int tt=1;tt<=T;tt++)
//template ends//
set<long long> st;
void up(long long &x) {
    x++;
    while(st.count(x)) x++;
}
 
void down(long long &x) {
    x--;
    while(st.count(x)) x--;
    
}
int main() {
    fast;
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
 
        st.clear();
        long long mid = 0;
            mid |= (1LL << (m-1))-1;
        long long sz = 1 << m;
        for (int i=0; i<n; i++) {
            string s;
            cin >> s;
 
            long long a = 0;
            for (int j=0; j<m; j++) {
                if (s[s.length()-j-1] == '1')
                    a |= 1LL << j;
            }
            st.insert(a);
            if (a == mid) {
                if (sz % 2)
                    down(mid);
                else
                    up(mid);
            }
            else if (a < mid) {
                if (sz % 2 == 0)
                    up(mid);
            } else {
                if (sz % 2)
                    down(mid);
            }
            sz--;
        }
 
 
        for (int j=m-1; j>=0; j--)
            cout << ((mid >> j) & 1);
        cout << "\n";
    }
}