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
int main(){
    ll t;
    string s;
    cin >> t;
    while(t--){
        cin >> s;
        ll a1,a2,a3,ans;
        a1=a2=a3=-1000000;
        ans=100000000;
        for(int i=0;i<s.length();i++){
            if(s[i]=='1'){
                ans=min(ans,i-min(a2,a3)+1);
                a1=i;
            }
            else if(s[i]=='2'){
                ans=min(ans,i-min(a1,a3)+1);
                a2=i;
            }
            else if(s[i]=='3'){
                ans=min(ans,i-min(a2,a1)+1);
                a3=i;
            }
        }
        if(ans>s.length()){
            cout<<0<<endl;
        }
        else{
            cout<<ans<<endl;
        }
    }
}