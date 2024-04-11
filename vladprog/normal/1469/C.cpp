#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100;

int h[N],l[N],r[N];

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
            cin>>h[i];
        l[1]=h[1],r[1]=h[1];
        bool ok=true;
        for(int i=2;i<=n;i++)
        {
            l[i]=max(l[i-1]-k+1,h[i]);
            r[i]=min(r[i-1]+k-1,h[i]+k-1);
            if(l[i]>r[i])
                ok=false;
        }
//        for(int i=1;i<=n;i++)
//            cout<<h[i]<<" -> "<<l[i]<<" "<<r[i]<<"\n";
        cout<<(ok&&l[n]==h[n]?"YES\n":"NO\n");
    }
}