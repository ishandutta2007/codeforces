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

ll a[100005],aa[100005];
int main() {
    int n;
    cin>>n;
    ii cin>>a[i],aa[i]=a[i];
    if(n==1) {cout<<1<<" "<<1<<endl<<-a[n]<<endl;cout<<"1 1\n0\n1 1\n0\n";return 0;}
    cout<<1<<" "<<n<<endl;
    for(int i=1;i<=n;++i) cout<<-aa[i]*n<<" ",a[i]-=aa[i]*n;cout<<endl;
    cout<<1<<" "<<n-1<<endl;
    for(int i=1;i<=n-1;++i) cout<<aa[i]*(n-1)<<" ",a[i]+=aa[i]*(n-1);cout<<endl;
    cout<<n<<" "<<n<<endl;
    cout<<-a[n]<<endl;a[n]=0;
}