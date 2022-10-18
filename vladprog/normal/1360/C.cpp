#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=55;

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
        int n;
        cin>>n;
        int cnt[2]={};
        for(int i=1;i<=n;i++)
            cin>>a[i],
            cnt[a[i]%2]++;
        bool ok=cnt[0]%2==0;
        sort(a+1,a+n+1);
        for(int i=1;i<=n-1;i++)
            if(a[i]+1==a[i+1])
                ok=true;
        cout<<(ok?"YES\n":"NO\n");
    }
}