#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e5+100;

int a[2*N],b[2*N],sa[2*N],sb[2*N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=n;i++)
            cin>>b[i];
        sort(a+1,a+n+1);
        sort(b+1,b+n+1,greater<>());
        for(int i=1;i<=n;i++)
            sa[i]=sa[i-1]+a[i];
        for(int i=1;i<=n;i++)
            sb[i]=sb[i-1]+b[i];
        int k=n;
        while(true)
        {
            int m=k-k/4;
            int A=sa[k]-sa[k-m];
            int B=sb[m];
            if(A>=B)
                break;
            k++;
            a[k]=100;
            b[k]=0;
            sa[k]=sa[k-1]+a[k];
            sb[k]=sb[k-1]+b[k];
        }
        cout<<k-n<<"\n";
    }
}