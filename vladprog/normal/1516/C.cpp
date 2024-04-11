#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=110,A=2010;

int a[N];
bitset<N*A> b;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    b.reset();
    b.set(0);
    int s=0;
    for(int i=1;i<=n;i++)
        cin>>a[i],
        b|=b<<a[i],
        s+=a[i];
    if(s%2==0&&b[s/2])
    {
        int g=0;
        for(int i=1;i<=n;i++)
            g=__gcd(g,a[i]);
        for(int i=1;i<=n;i++)
            a[i]/=g;
        int ind=0;
        for(int i=1;i<=n;i++)
            if(a[i]%2)
                ind=i;
        cout<<1<<"\n"<<ind;
    }
    else
        cout<<0;
}