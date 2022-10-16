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
int solve(string s,int f,int step,int cord)
{
    int ans=0;
    if(step==s.size()+1&&cord==f)
    {
        //cout<<cord<<" "<<f<<" "<<step<<"\n";
        ans++;
    }
    else if(step==s.size()+1) return 0;
    else
    {
        if(s[step-1]=='+') ans+=solve(s,f,step+1,cord+1);
        else if(s[step-1]=='-') ans+=solve(s,f,step+1,cord-1);
        else
        {
            ans+=solve(s,f,step+1,cord+1);
            ans+=solve(s,f,step+1,cord-1);
        }
    }
    return ans;
}
int main()
{
    fast;
    string s1,s2;
    cin>>s1>>s2;
    int final=0,finale=0;
    for(int i=0;i<s1.size();i++)
    {
        if(s1[i]=='+') final++;
        else final--;
    }

    int n=s1.size();
    int c=0;
    for(int i=0;i<s2.size();i++)
    {
        if(s2[i]=='?') c++;
        else if(s2[i]=='+') finale++;
        else finale--;
    }   
    if(c) 
        {
            int x=solve(s2,final,1,0);
            //out<<x<<'\n';
            double y=pow(2,c);
            cout<<fixed<<setprecision(15)<<x/y;

        }
    else
    {
        if(final==finale) cout<<fixed<<setprecision(15)<<1;   
        else cout<<0; 
    }
    cout<<'\n';

}