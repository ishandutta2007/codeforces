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
#define pi pair<int,int>
#define pl pair<ll,ll>
#define vpi vector<pi>
#define vpl vector<pl>
#define vinput(a,n,v) for(int i=a;i<n;i++) cin>>v[i];
typedef double dd;
typedef long long ll;
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
int main()
{
    fast;
    int n;
    cin>>n;
    vi m(n);
    vinput(0,n,m);
    vi prefix(n),suffix(n);
    suffix[n-1]=m[n-1];
    prefix[0]=m[0];
    for(int i=1;i<n;i++)
    {
        prefix[i]=min(m[i],prefix[i-1]);
    }
    for(int i=n-2;i>=0;i--)
    {
        suffix[i]=min(suffix[i+1],m[i]);
    }
    vl l(n);
    vl r(n);
    stack<pl> s;
    for(int i=0;i<n;i++)
    {
        if(m[i]==prefix[i])
        {
            while(!s.empty()) s.pop();
            s.push({m[i],i});
            l[i]=(i+1)*m[i];
        }
        else
        {
            while(!s.empty()&&s.top().F>m[i])
            {
                s.pop();
            }
            l[i]=l[s.top().S] + (i-s.top().S)*m[i];
            s.push({m[i],i});
        }
    }
    while(!s.empty()) s.pop();
    for(int i=n-1;i>=0;i--)
    {
        if(m[i]==suffix[i])
        {
            while(!s.empty()) s.pop();
            s.push({m[i],i});
            r[i]=(n-1-i+1)*m[i];
        }
        else
        {
            while(!s.empty()&&s.top().F>m[i]) s.pop();
            r[i]=r[s.top().S]+ (s.top().S-i)*m[i];
            s.push({m[i],i});
        }
    }
    ll ans=0;
    vi a(n);
    int index=0;
    for(int i=0;i<n;i++)
    {
        if(l[i]+r[i]-m[i]>ans)
        {
            ans=max(ans,l[i]+r[i]-m[i]);
            index=i;
        }   
    }  
    int current_min=m[index];
    a[index]=m[index];
    for(int i=index+1;i<n;i++)
    {
        current_min=min(m[i],current_min);
        a[i]=current_min;
    }
    current_min=m[index];
    for(int i=index-1;i>=0;i--)
    {
        current_min=min(current_min,m[i]);
        a[i]=current_min;
    }   
    printvector(a);

     
}