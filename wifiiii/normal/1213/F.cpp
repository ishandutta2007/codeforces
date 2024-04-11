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

const int maxn = 200005;
int a[maxn], b[maxn], id[maxn];
int par[maxn];
int find(int x) {return x==par[x]?x:par[x]=find(par[x]);}
char ans[maxn];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,k;
    cin>>n>>k;
    ii par[i]=i;
    ii cin>>a[i];
    ii cin>>b[i];
    ii id[a[i]]=i;
    ii b[i]=id[b[i]];
    ii
    {
        int l=i,r=b[i];
        if(l>r) swap(l,r);
        int x = find(r);
        for(int i=l,nxt;i<r;i=nxt)
        {
            nxt = find(i)+1;
            par[find(i)] = x;
        }
    }
    int cnt=0;
    ii if(i==par[i]) cnt++;
    if(cnt<k) cout<<"NO"<<endl;
    else
    {
        cout<<"YES"<<endl;
        int idx = 0;
        ii
        {
            ans[i] = (char)('a'+idx);
            if(idx < 25 && find(i) != find(i+1)) idx++;
        }
        for(int i=1;i<=n;++i) cout<<ans[id[i]];
    }
}