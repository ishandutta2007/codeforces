#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e4+100;

int a[N];

void op(int i,int j,int x)
{
    cout<<i<<" "<<j<<" "<<x<<"\n";
    a[i]-=i*x;
    a[j]+=i*x;
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
        int n;
        cin>>n;
        int res=0;
        for(int i=1;i<=n;i++)
            cin>>a[i],
            res+=a[i];
        if(res%n)
            cout<<-1<<"\n";
        else
        {
            res/=n;
            cout<<3*(n-1)<<"\n";
            for(int i=2;i<=n;i++)
                op(1,i,(i-a[i]%i)%i),
                op(i,1,a[i]/i);
            for(int i=2;i<=n;i++)
                op(1,i,res);
        }
    }
}