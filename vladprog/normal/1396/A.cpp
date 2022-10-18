#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e5+100;

int a[N];

int ppow(int x,int y,int mod)
{
    int res=1;
    while(y)
    {
        if(y&1)
            res=res*x%mod;
        y>>=1;
        x=x*x%mod;
    }
    return res;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];

    if(n==1)
    {
        cout<<"1 1\n"<<-a[1]<<"\n1 1\n0\n1 1\n0";
        exit(0);
    }

    int phi=0;
    for(int i=1;i<=n-1;i++)
        phi+=__gcd(i,n-1)==1;

    cout<<1<<" "<<n<<"\n";
    for(int i=1;i<=n;i++)
    {
        int x=a[i];
        int k=(-x)%(n-1)*ppow(n,phi-1,n-1)%(n-1);
        k+=n-1;
        k%=n-1;
        cout<<k*n<<" ";
        a[i]+=k*n;
    }
    cout<<"\n";

    cout<<1<<" "<<n-1<<"\n";
    for(int i=1;i<=n-1;i++)
        cout<<-a[i]<<" ";
    cout<<"\n";

    cout<<n<<" "<<n<<"\n";
    cout<<-a[n]<<"\n";
}