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

    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        int s=0;
        for(int i=1;i<=n;i++)
            s+=a[i];
        if(s%x!=0)
            cout<<n<<"\n";
        else
        {
            int fir=n+1,las=0;
            for(int i=1;i<=n;i++)
                if(a[i]%x!=0)
                    fir=min(fir,i),
                    las=max(las,i);
            if(!las)
                cout<<-1<<"\n";
            else
                cout<<max(las-1,n-fir)<<"\n";
        }
    }
}