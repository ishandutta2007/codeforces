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

int a[300005],aa[300005];
int l[300005], r[300005];
int st[300005][22];
int query(int l,int r)
{
    int k=0;
    while((1<<k)<=r-l+1) ++k;--k;
    return min(st[l][k],st[r-(1<<k)+1][k]);
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int q;
    cin>>q;
    while(q--)
    {
        int n;
        cin>>n;
        ii cin>>a[i],aa[i]=a[i];
        sort(aa+1,aa+1+n);
        int len=unique(aa+1,aa+1+n)-1-aa;
        ii a[i]=lower_bound(aa+1,aa+1+len,a[i])-aa;
        set<int> s;
        for(int i=1;i<=len;++i) l[i]=1e9;
        for(int i=1;i<=n;++i)
        {
            auto p = s.upper_bound(a[i]);
            if(p!=s.end()) l[a[i]] = min(l[a[i]],*p);
            s.insert(a[i]);
        }
        for(int i=1;i<=len;++i) st[i][0]=l[i];
        for(int j=1;j<=20;++j)
            for(int i=1;i+(1<<j)-1<=len;++i)
                st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
        int ans = len - 1;
        for(int i=2;i<=len;++i)
        {
            if(query(1, i-1) > i) {ans = min(ans, len - i);continue;}
            int lo = 1, hi = i-1;
            while(lo < hi)
            {
                int mid = (lo+hi+1)/2;
                if(query(mid, i-1) <= i) lo = mid;
                else hi = mid-1;
            }
            ans = min(ans, lo + len - i);
        }
        cout<<ans<<endl;
    }
}