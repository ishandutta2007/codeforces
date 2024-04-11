#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
//mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 mrand(42);
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define al(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define asdd cout<<"okok"<<endl;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pr(v) for(auto i:v) cout<<i<<" ";cout<<endl;
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back
#define PS string qqwwee;cin>>qqwwee;
typedef pair<int,int> pii;

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        int ok = 1;
        for(int i=0;i<k;++i) {
            int c0=0,c1=0;
            for(int j=i;j<n;j+=k) {
                if(s[j] == '0') c0++;
                else if(s[j] == '1') c1++;
            }
            if(c0 && c1) {ok = 0; break;}
            if(c0) for(int j=i;j<n;j+=k) s[j]='0';
            else if(c1) for(int j=i;j<n;j+=k) s[j]='1';
        }
        int c1=0,c0=0;
        for(int i=0;i<k;++i) if(s[i]=='1') c1++;else if(s[i]=='0') c0++;
        if(c1 > k/2 || c0 > k/2 || !ok) {cout<<"NO"<<endl;continue;}
        else cout<<"YES"<<endl;
    }
}