#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(),x.end()
#define answer(x) cout << (x ? "YES\n" : "NO\n")
#define test ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); int T; cin >> T; while(T--)
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb(x) push_back(x)
#define F first
#define S second
using namespace std;


int mul(int x,int y,int mod)
{
    return (ll) x*y %mod;
}
int sum(int x,int y,int mod)
{
    return (x+y) %mod;
}
int sub(int x,int y,int mod)
{
    return sum((x-y)%mod,mod,mod);
}
int po(int x,int y,int mod)
{
    if(!y) return 1;
    if(y&1) return mul(x,po(x,y-1,mod),mod);
    int z=po(x,y/2,mod);
    return mul(z,z,mod);
}
int inv(int x,int mod)
{
    return po(x,mod-2,mod);
}
struct Hash
{
    int n,Base,Mod,Inv;
    vector <int> Po,Pre;
    Hash(string &s,int base,int mod)
    {
        Mod=mod;
        Base=base;
        Po.reserve(s.size() + 1);
        Pre.reserve(s.size() + 1);
        Po.pb(1);
        Pre.pb(0);
        Inv=inv(base,Mod);
        for(int i=1; i<=(int)s.size(); i++)
            Add(s[i-1]);
    }
    void Add(char c)
    {
        Po.pb(mul(Base,Po.back(),Mod));
        Pre.pb(sum(mul(Pre.back(),Base,Mod),c,Mod));
    }
    int G(int L,int R)
    {
        R++;
        return sub(Pre[R], mul(Pre[L],Po[R-L],Mod), Mod);
    }
};

const int N = 5000001;  
int n, ans; 
string s; 
int h11[N], h21[N]; 
vector<int> dp; 


int f (int i)
{
    if(i == 0) return 1; 
    if(dp[i]) return dp[i]; 

    if(h11[i] == h21[n - 1 -i])
        return dp[i] = 1 + f(i/2 - (i % 2 == 0));

    return 0; 
}


int main()
{
    go; 
    cin >> s, n = s.length(); 

    Hash s1_1(s, 1337, 1e9 + 7);    
    for(int i=0 ;i <n; i++)
        h11[i] = s1_1.G(0, i);
        
    s1_1.Po.clear(); 
    s1_1.Pre.clear(); 
    
    reverse(all(s)); 

    Hash s2_1(s, 1337, 1e9 + 7); 
    for(int i=0 ;i<n; i++)
        h21[i] = s2_1.G(i,n-1);
    
    s2_1.Po.clear();
    s2_1.Pre.clear();       
    dp.resize(n + 1);
    for(int i=0 ; i<n; i++)
        dp[i] = 0;

    for(int i=n-1; i>=0; i--)
        ans += f(i);
        
    cout << ans; 
}