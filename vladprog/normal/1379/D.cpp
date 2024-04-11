#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e5+100;

int hi[N],mi[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,h,m,k;
    cin>>n>>h>>m>>k;
    m/=2;
    map<int,int> pref;
    pref[2*m];
    for(int i=1;i<=n;i++)
    {
        cin>>hi[i]>>mi[i];
        mi[i]%=m;
        pref[mi[i]]++;
        pref[mi[i]+m]++;
    }
    int sum=0;
    for(auto&p:pref)
        sum=p.y+=sum;
    pii ans(1e9,-1);
    for(auto&p:pref)
    {
        if(p.x>=m)
            break;
        int l=p.x,r=p.x+k;
        int sub=p.y;
        int add=prev(pref.lower_bound(r))->y;
        ans=min(ans,{add-sub,r%m});
    }
    cout<<ans.x<<" "<<ans.y<<"\n";
    for(int i=1;i<=n;i++)
        if(ans.y-k<mi[i]&&mi[i]<ans.y||
           ans.y+m-k<mi[i]&&mi[i]<ans.y+m)
            cout<<i<<" ";
}