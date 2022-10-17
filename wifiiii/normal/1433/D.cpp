#include<bits/stdc++.h>

typedef long long ll;
typedef long long LL;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 mrand(42);
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

int a[5005],ord[5005];
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        for(int i=1;i<=n;++i) cin>>a[i];
        for(int i=1;i<=n;++i) ord[i]=i;
        sort(ord+1,ord+1+n,[&](int i,int j){return a[i]<a[j];});
        if(a[ord[1]] == a[ord[n]]) {cout<<"NO"<<endl;continue;}
        cout<<"YES"<<endl;
        cout<<ord[1]<<" "<<ord[n]<<endl;
        for(int i=2;i<=n-1;++i) {
            if(a[ord[i]] == a[ord[1]]) cout << ord[i] << " " << ord[n] << endl;
            else cout << ord[i] << " " << ord[1] << endl;
        }
    }
}