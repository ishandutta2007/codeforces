
#include<bits/stdc++.h>
 
typedef long long ll;
using namespace std;
random_device rng;
mt19937 rd(rng());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i )
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'
 
int mx[200005];
int st[200005][22];
int query(int l,int r)
{
    int k=0;
    while((1<<k)<=r-l+1) ++k;--k;
    return max(st[l][k],st[r-(1<<k)+1][k]);
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int MXM = 0;
        for(int i=1;i<=n;++i) cin>>st[i][0], MXM = max(MXM, st[i][0]);
        for(int j=1;j<=21;++j)
            for(int i=1;i+(1<<j)-1<=n;++i)
                st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
        int m;
        cin>>m;
        for(int i=1;i<=n;++i) mx[i]=0;
        int MX = 0;
        for(int i=1;i<=m;++i)
        {
            int p,s;
            cin>>p>>s;
            s=min(s,n);
            mx[s] = max(mx[s], p);
            MX = max(MX, p);
        }
        if(MXM > MX) {cout<<-1<<endl;continue;}
        for(int i=n-1;i>=1;--i) mx[i]=max(mx[i],mx[i+1]);
        int HI = n;
        while(mx[HI] == 0) HI--;
        int cnt = 0;
        for(int i=1;i<=n;cnt++)
        {
            int lo = 1, hi = min(HI, n-i+1);
            while(lo < hi)
            {
                int mid = (lo+hi+1)>>1;
                if(mx[mid] >= query(i, i+mid-1)) lo = mid;
                else hi = mid - 1;
            }
            i += lo;
        }
        cout<<cnt<<endl;
    }
}