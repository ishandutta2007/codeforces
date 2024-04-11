#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100;

int c[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,a,b,k;
    cin>>n>>a>>b>>k;
    for(int i=1;i<=n;i++)
    {
        int h;
        cin>>h;
        h--;
        h%=a+b;
        h++;
        c[i]=(h-1)/a;
    }
    sort(c+1,c+n+1);
    int ans=0;
    for(int i=1;i<=n;i++)
        if(c[i]<=k)
            ans++,
            k-=c[i];
    cout<<ans<<"\n";
}