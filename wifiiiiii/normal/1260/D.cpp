#include<bits/stdc++.h>
 
typedef long long ll;
using namespace std;
//random_device rng;
//mt19937 rd(rng());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

int cnt[200005];
struct node {
    int l,r,d;
}a[200005];
int b[200005];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int m,n,k,t;
    cin>>m>>n>>k>>t;
    for(int i=1;i<=m;++i)
    {
        int tmp;
        cin>>tmp;
        cnt[tmp]++;
    }
    for(int i=1;i<=k;++i) cin>>a[i].l>>a[i].r>>a[i].d;
    int lo=0,hi=200001;
    while(lo<hi)
    {
        int mid=(lo+hi)>>1;
        memset(b,0,sizeof(b));
        for(int i=1;i<=k;++i)
        {
            if(a[i].d <= mid) continue;
            b[a[i].l]++;
            b[a[i].r+1]--;
        }
        for(int i=1;i<=n;++i) b[i]+=b[i-1];
        int tot = n + 1;
        for(int i=1;i<=n;++i) if(b[i]>0) tot += 2;
//        cout << mid << " " << tot << endl;
        if(tot <= t) hi = mid;
        else lo = mid + 1;
    }
    int ans=0;
    for(int i=lo;i<=200000;++i) ans+=cnt[i];
    cout<<ans<<endl;
}