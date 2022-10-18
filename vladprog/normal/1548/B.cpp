#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100,L=20;

int a[N],st[N][L+1],lg2[N];

int get(int l,int r)
{
    if(l>r)
        return 47;
    int len=r-l+1;
    int j=lg2[len];
    return __gcd(st[l][j],st[r-(1<<j)+1][j]);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    lg2[1]=0;
    for(int i=2;i<N;i++)
        lg2[i]=lg2[i/2]+1;

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=n-1;i++)
            st[i][0]=abs(a[i]-a[i+1]);
        n--;
        for(int j=1;j<=L;j++)
            for(int i=1;i+(1<<j)-1<=n;i++)
                st[i][j]=__gcd(st[i][j-1],st[i+(1<<(j-1))][j-1]);
        int ans=0;
        for(int l=1,r=1;r<=n;)
            if(get(l,r)==1)
                l++;
            else
                ans=max(ans,r-l+1),
                r++;
        cout<<ans+1<<"\n";
    }
}