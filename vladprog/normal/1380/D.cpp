#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100,INF=1e18;

int a[N];
bool del[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;
    int x,k,y;
    cin>>x>>k>>y;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        del[i]=true;
    int pos=1;
    while(m--)
    {
        int b;
        cin>>b;
        while(pos<=n&&a[pos]!=b)
            pos++;
        if(pos>n)
            cout<<-1,exit(0);
        del[pos]=false;
    }
    int ans=0;
    for(int l=1;l<=n;l++)
        if(del[l])
        {
            int r=l;
            while(del[r+1])
                r++;
            int len=r-l+1;
            int mx=*max_element(a+l,a+r+1);
            bool can_del_all=mx<a[l-1]||mx<a[r+1];
            int cost=INF;
            if(can_del_all)
                cost=min(cost,y*len);
            if(len>=k)
                cost=min(cost,y*(len-k)+x),
                cost=min(cost,len%k*y+len/k*x);
//            cout<<l<<" "<<r<<" -> "<<len<<" "<<mx<<" "<<can_del_all<<" -> "<<cost<<"\n";
            if(cost==INF)
                cout<<-1,exit(0);
            else
                ans+=cost;
            l=r;
        }
    cout<<ans;
}