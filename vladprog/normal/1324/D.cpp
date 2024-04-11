#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100;

int d[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>d[i];
    for(int i=1;i<=n;i++)
    {
        int b;
        cin>>b;
        d[i]-=b;
    }
    sort(d+1,d+n+1);
//    for(int i=1;i<=n;i++)
//        cout<<d[i]<<" ";
//    cout<<"\n";
    int ans=0;
    for(int i=1,j=n+1;i<=n;i++)
    {
        while(j-1>i&&d[i]+d[j-1]>0)
            j--;
        j=max(j,i+1);
        ans+=n-j+1;
    }
    cout<<ans;
}