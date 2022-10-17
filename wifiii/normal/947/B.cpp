#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define fe(i,n) for(int i=1;i<=n;++i)
#define ff(i,n) for(int i=0;i<n;++i)
#define fs(i,s) for(int i=0;i<s.size();++i)
#define sz(x) ((int) x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'
const int mod = 1e9+7;


const int maxn = 1e5+5;
ll a[maxn],b[maxn],c[maxn],d[maxn];
int n;
void add(int a,int b) {for(;a<=n;a+=a&-a) c[a]+=b;}
ll sum(int a) {ll ret=0;for(;a;a-=a&-a) ret+=c[a];return ret;}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    ii cin>>a[i];
    ii cin>>b[i];
    ii b[i]+=b[i-1];
    ii
    {
        int pos=lower_bound(b+1,b+1+n,a[i]+b[i-1])-b-1;
        d[pos+1] += a[i]-(b[pos]-b[i-1]);
        c[i]++,c[pos+1]--;
    }
    ii c[i]+=c[i-1];
    ii cout<<(b[i]-b[i-1])*c[i]+d[i]<<" ";cout<<endl;
}