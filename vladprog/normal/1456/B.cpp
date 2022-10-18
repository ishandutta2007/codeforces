#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e5+100,INF=1e9;

int a[N],x[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n-2;i++)
        if((a[i]^a[i+1])>a[i+2])
            cout<<1,exit(0);
    for(int i=2;i<=n-1;i++)
        if((a[i]^a[i+1])<a[i-1])
            cout<<1,exit(0);
    for(int i=1;i<=n;i++)
        x[i]=x[i-1]^a[i];
    int ans=INF;
    for(int l=1;l<=n;l++)
        for(int r=l;r<=n;r++)
        {
            int cur=x[r]^x[l-1];
            if(l>1&&cur<a[l-1])
                ans=min(ans,r-l);
            if(r<n&&cur>a[r+1])
                ans=min(ans,r-l);
        }
    for(int l1=1;l1<=n;l1++)
        for(int r1=l1;r1<=n;r1++)
            for(int l2=r1+1;l2<=n;l2++)
                for(int r2=l2;r2<=n;r2++)
                {
                    int cur1=x[r1]^x[l1-1];
                    int cur2=x[r2]^x[l2-1];
                    if(cur1>cur2)
                        ans=min(ans,r1-l1+r2-l2);
                }
    cout<<(ans==INF?-1:ans);
}