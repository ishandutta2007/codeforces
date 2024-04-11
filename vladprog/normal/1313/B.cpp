#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=5e5+100;

int m[N],pref[N],suff[N],a[N];

int len(int l,int r)
{
    return r-(l-1);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,x,y;
        cin>>n>>x>>y;
        int s=x+y;
        {
            if(n+1>s)
                cout<<1<<" ";
            else
            {
                int r=n,l=s+1-r;
                cout<<n-(r-l+1-(l<=x&&x<=r||l<=y&&y<=r))<<" ";
            }
        }
        {
            if(n+1<=s)
                cout<<n<<"\n";
            else
            {
                int l=1,r=s-l;
                cout<<r-l+1-(l<=x&&x<=r||l<=y&&y<=r)+1<<"\n";
            }
        }
    }
}