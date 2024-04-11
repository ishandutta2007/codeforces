
#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
//mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define al(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define asdasd cout<<"okok"<<endl;
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pr(v) for(auto i:v) cout<<i<<" ";cout<<endl
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define endl '\n'


int a[200005][26];
int solve(int l,int r,int k) {
    if(k>26) return 1e7;
    if(l==r) return 1-(a[r][k]-a[l-1][k]);
    int ret=1e9;
    int m=(l+r)/2;
    ret=min(ret,(m-l+1)-(a[m][k]-a[l-1][k])+solve(m+1,r,k+1));
    ret=min(ret,(r-m)-(a[r][k]-a[m][k])+solve(l,m,k+1));
    return ret;
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        string s;
        cin>>s;
        for(int i=1;i<=n;++i) {
            char c=s[i-1];
            for(int j=0;j<26;++j) a[i][j]=a[i-1][j];
            a[i][c-'a']=a[i-1][c-'a']+1;
        }
        cout<<solve(1,n,0)<<endl;
    }
}