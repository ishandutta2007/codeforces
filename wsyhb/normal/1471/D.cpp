//debug
//
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
//
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
#define pb push_back
#define bp pop_back
#define int long long int
#define vt vector
#define pii pair<int,int>
#define pq priority_queue
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define FOR(i, a, b) for (int i=a; i<(b); ++i)
#define F0R(i, a) for (int i=0; i<(a); ++i)
#define um unordered_map
#define us unordered_set
#define bs binary_search
#define endl '\n'

int M=1e9+7;
const int N=1000005; 

int mpower(int x, unsigned int y){  
    int res = 1;
    x = x % M;
    if (x == 0) return 0;
    while (y)  
    {  
        if (y & 1)  
            res = (res*x) % M;  
        y = y>>1;
        x = (x*x) % M;  
    }  
    return res;  
}
int gcdExtended(int a, int b, int *x, int *y); 

int modInverse(int b, int m) { 
    int x, y;
    int g = gcdExtended(b, m, &x, &y); 
    if (g != 1) 
        return -1; 
    return (x%m + m) % m; 
} 
 
int gcdExtended(int a, int b, int *x, int *y) { 
    if (a == 0) 
    { 
        *x = 0, *y = 1; 
        return b; 
    } 
    int x1, y1;
    int gcd = gcdExtended(b%a, a, &x1, &y1); 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
    return gcd; 
} 
void solve();
 
int spf[N];
void sieve(){
    FOR(i,1,N) spf[i]=i;
    for(int i=2;i*i<N;++i){
        if(spf[i]==i){
            for(int j=i*i;j<N;j +=i)
            {
                if(spf[j]==j)
                    spf[j]=i;
            }
        }
    } 
}
int32_t main()
{ 
    ios_base::sync_with_stdio(false);cin.tie(NULL);
 
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
    #endif
    sieve();
    int t;
    cin>>t;
    while(t--)
        solve();
    cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
    return 0; 
}
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
vt<int> getfactorisation(int n){
    vt<int> ans={1};
    um<int,int> m;
    while(n !=1){
        if(m[spf[n]]) m[spf[n]] +=1;
        else
            m[spf[n]]=1;
        n /=spf[n];
    }
    for(auto i:m)
    {
        if(i.ss&1)
            ans.pb(i.ff);
    }
    sort(all(ans));
    return ans;
}
void solve(){
    int n,q,w;
    cin>>n;
    vt<int> a(n),temp;
    map<vt<int>,int> m;
    int ma=0,c=0;
    F0R(i,n){
        cin>>a[i];
        temp=getfactorisation(a[i]);
        // for(auto j:temp) cout<<j<<" ";
        //     cout<<endl;
        if(m[temp]) m[temp] +=1;
        else
            m[temp]=1;
    }
    for(auto i:m){
        // cout<<i.ss<<" ";
        ma=max(ma,i.ss);
        if(i.ss%2==0 || i.ff.size()==1)
            c +=(int)i.ss;
    }
    // cout<<endl;
    cin>>q;
    while(q--){
        cin>>w;
        cout<<(w==(int)0 ? ma:max(ma,c))<<endl;
    }
}