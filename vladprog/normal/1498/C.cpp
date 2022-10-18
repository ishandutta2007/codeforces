#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first

const int N=1010,MOD=1e9+7;

int a[2][N];
int pref[N];

void gen(int arr[],int n)
{
    for(int i=1;i<=n;i++)
        pref[i]=(pref[i-1]+arr[i])%MOD;
}

int get(int l,int r)
{
    return (pref[r]-pref[l-1]+MOD)%MOD;
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
        int n,k;
        cin>>n>>k;
        for(int j=1;j<=n;j++)
            a[0][j]=1;
        int ans=1;
        gen(a[0],n);
        for(int i=1;i<=k-1;i++)
        {
            ans=(ans+get(1,n))%MOD;
            for(int j=1;j<=n;j++)
                a[i%2][j]=(i%2?get(j+1,n):get(1,j-1));
            gen(a[i%2],n);
        }
        cout<<ans<<"\n";
    }
}