#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100;

int a[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i],
        a[i]=abs(a[i]);
    sort(a+1,a+n+1);
    int ans=0;
    for(int i=1,j=1;i<=n;i++)
    {
        while(j+1<=n&&a[j+1]<=a[i]*2)
            j++;
        ans+=j-i;
    }
    cout<<ans;
}