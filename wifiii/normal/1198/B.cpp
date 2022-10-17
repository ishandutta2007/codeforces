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

int a[200005];
int mx=-1;
pair<int,int> b[200005],c[200005];int tp=0;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    ii cin>>a[i];
    int q;
    cin>>q;
    ii b[i].first=0;
    for(int i=1;i<=q;++i)
    {
        int op;
        cin>>op;
        if(op==1)
        {
            int p,x;
            cin>>p>>x;
            b[p]={i,x};
        }
        else
        {
            int x;
            cin>>x;
            while(tp && c[tp].second<x) tp--;
            c[++tp] = {i,x};
        }
    }
    ii
    {
        if(b[i].first > c[tp].first)
        {
            cout<<b[i].second<<" ";
            continue;
        }
        int pos = lower_bound(c+1, c+1+tp, b[i])-c;
        int ans = 0;
        if(!b[i].first) ans=a[i];
        else ans=b[i].second;
        ans=max(ans,c[pos].second);
        cout<<ans<<" ";
    }
    cout<<endl;
}