#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e5+100;

int a[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int ans=0;
    for(int m=-30;m<=30;m++)
    {
        int res=0;
//        cout<<m<<" :\n";
        for(int i=1;i<=n;i++)
        {
            if(a[i]<=m&&res+a[i]>=0)
                res+=a[i],
//                cout<<i<<" -> "<<res<<"\n",
                ans=max(ans,res-m);
            else
                res=0;
        }
    }
    cout<<ans;
}