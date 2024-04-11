#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i )
#define sz(x) ((int) x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'
 
int a[300005],b[300005],ans[100005];
int st[300005][22];
int query(int l,int r)
{
    int k=0;
    while((1<<k)<=r-l+1) ++k;--k;
    return max(st[l][k],st[r-(1<<k)+1][k]);
}
const int inf = 1e8;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    ii cin>>a[i],a[i+n+n]=a[i+n]=a[i];
    for(int i=1;i<=3*n;++i) b[i]=1e9;
    for(int i=1;i<=3*n;++i) st[i][0]=a[i];
    for(int j=1;j<=21;++j)
        for(int i=1;i+(1<<j)-1<=3*n;++i)
            st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
    int last = 1;
    for(int i=2;i<=3*n;++i)
    {
        int lo = 1, hi = i-1;
        if(query(lo, hi) <= 2*a[i]) continue;
        while(lo < hi)
        {
            int mid = (lo+hi+1)/2;
            if(query(mid, hi) <= 2*a[i]) hi = mid-1;
            else lo = mid;
        }
        while(last <= lo)
        {
            b[last] = i;
            last++;
        }
        if(last > n) break;
    }
    ii
    {
        if(b[i]-i > inf) cout<<"-1 ";
        else cout<<b[i]-i<<" ";
    }
    cout<<endl;
}