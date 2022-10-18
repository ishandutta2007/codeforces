#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100;

int a[N],b[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=n;i++)
            cin>>a[i],
            b[i]=a[i];
        sort(b+1,b+n+1);
        int g=(n+k+1)/2;
        int x=1,y=n;
        for(int i=1;i+g-1<=n;i++)
            if(b[i+g-1]-b[i]<y-x)
                x=b[i],
                y=b[i+g-1];
        cout<<x<<" "<<y<<"\n";
        int d=0,l=1,cnt=0;
        for(int i=1;i<=n&&cnt<k-1;i++)
        {
            d+=(x<=a[i]&&a[i]<=y?1:-1);
            if(d>0)
                cout<<l<<" "<<i<<"\n",
                l=i+1,
                cnt++,
                d=0;
        }
        cout<<l<<" "<<n<<"\n";
    }
}