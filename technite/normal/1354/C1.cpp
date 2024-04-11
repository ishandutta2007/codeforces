#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define F first
#define S second
#define pb push_back
#define forn(i, n) for(int i = 0; i < n; ++i)
#define forl(i, n) for(long long i=0;i<n;++i)
typedef double dd;
typedef long long ll;
ll exp(ll n, ll m, ll md){
    ll a = 1;
    while (m > 0){
        if (m&1) a = (a * n%md) % md;
        m /= 2;
        n = (n*n) % md;
    }
    return a % md;
}
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
#define TT int T;cin>>T;for(int tt=1;tt<=T;tt++)
float polydiagonal(float n, float a) 
{ 
  
    // Side and side length cannot be negative 
    if (a < 0 && n < 0) 
        return -1; 
  
    // diagonal 
    // degree converted to radians 
    return 2 * a * sin((((n - 2) * 180) / (2 * n)) * 3.14159 / 180); 
} 
 
int main()
{
    TT
    {
        double pi=2*acos(0.0);
        double n;
        cin>>n;
        n=(2.000000000000)*n;
        double side=1;
        double angle= (n-2)*180/n*(pi)/180;
        //cout<<angle;
        float x=pi-angle;
        //cout<<side<<"\n";
        for(int i=1;i<=n/4-1;i++)
        {
            //cout<<x<<"\n";
            side+=(2.000000)*cos(x);
            x+=pi-angle;
        }
        cout<<fixed<<setprecision(20)<<side<<"\n";
    }


}