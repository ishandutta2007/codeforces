//By TheOneYouWant

#pragma GCC optimize ("-O2")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define memreset(a) memset(a,0,sizeof(a))
#define testcase(t) int t;cin>>t;while(t--)
#define forstl(i,v) for(auto &i: v)
#define forn(i,e) for(int i = 0; i < e;++i)
#define forsn(i,s,e) for(int i = s; i < e;++i)
#define rforn(i,s) for(int i = s; i >= 0;--i)
#define rforsn(i,s,e) for(int i = s; i >= e;--i)
#define bitcount(a) __builtin_popcount(a) // set bits (add ll)
#define ln '\n'
#define getcurrtime ((double)clock()/CLOCKS_PER_SEC)
#define dbgarr(v,s,e) cerr<<#v<<" = "; forsn(i,s,e) cerr<<v[i]<<", "; cerr<<endl
#define inputfile freopen("input.txt", "r", stdin)
#define outputfile freopen("output.txt", "w", stdout)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> p64;
typedef pair<int,int> p32;
typedef pair<int,p32> p96;
typedef vector<ll> v64;
typedef vector<int> v32; 
typedef vector<v32> vv32;
typedef vector<v64> vv64;
typedef vector<p32> vp32;
typedef vector<p64> vp64;
typedef vector<vp32> vvp32;
typedef map<int,int> m32;

string doSum(string a, string b)
{
    if(a.size() < b.size())
        swap(a, b);

    int j = a.size()-1;
    for(int i=b.size()-1; i>=0; i--, j--)
        a[j]+=(b[i]-'0');

    for(int i=a.size()-1; i>0; i--)
    {
        if(a[i] > '9')
        {
            int d = a[i]-'0';
            a[i-1] = ((a[i-1]-'0') + d/10) + '0';
            a[i] = (d%10)+'0';
        }
    }
    if(a[0] > '9')
    {
        string k;
        k+=a[0];
        a[0] = ((a[0]-'0')%10)+'0';
        k[0] = ((k[0]-'0')/10)+'0';
        a = k+a;
    }
    return a;
}

const int LIM=1e5+5, MOD=1e9+7;
const ld EPS = 1e-9;

string minofstrings(string a, string b){
    if(a.size()==0) return b;
    if(b.size()==0) return a;
    if(a.size()>b.size()) return b;
    if(a.size()<b.size()) return a;
    if(a >= b) return b;
    return a;
}
// int t,n,m,k,x,y,w;
signed main(){
    fastio;
    
    ll l;
    cin>>l;
    string s;
    cin>>s;

    v32 v;

    string ans1, ans2, ans3;
    int n = s.length();
    if(s[n/2] != '0'){
        ans1 = doSum(s.substr(0,n/2), s.substr(n/2,n - n/2));
    }
    else{
        int g = n/2;
        int f = -1;
        rforn(i,n/2){
            if(s[i] != '0'){
                f = i;
                break;
            }
        }
        if(f!=-1) ans1 = doSum(s.substr(0,f), s.substr(f, n - f));
    }
    if(s[(n-1)/2] != '0'){
        ans2 = doSum(s.substr(0,(n-1)/2), s.substr((n-1)/2,n - (n-1)/2));
    }
    else{
        int g = (n-1)/2;
        int f = -1;
        forsn(i,(n-1)/2,n){
            if(s[i] != '0'){
                f = i;
                break;
            }
        }
        if(f!=-1)ans2 = doSum(s.substr(0,f), s.substr(f, n - f));
    }
    if(s[(n+1)/2] != '0'){
        ans3 = doSum(s.substr(0,(n+1)/2), s.substr((n+1)/2,n - (n+1)/2));
    }
    else{
        int g = (n+1)/2;
        int f = -1;
        forsn(i,(n+1)/2,n){
            if(s[i] != '0'){
                f = i;
                break;
            }
        }
        if(f!=-1)ans3 = doSum(s.substr(0,f), s.substr(f, n - f));
    }
    // cout<<ans1<<" "<<ans2<<" "<<ans3<<ln;
    ans1 = minofstrings(ans1, ans2);
    ans1 = minofstrings(ans1, ans3);
    cout<<ans1<<ln;

    // cout<<min({ans1,ans2,ans3})<<ln;

    return 0;
}