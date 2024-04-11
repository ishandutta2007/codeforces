#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e5+100;

int b[N];

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
        {
            int a;
            cin>>a;
            b[i]=(x+a-1)/a;
        }
        sort(b+1,b+n+1);
        int ans=0,nxt=1;
        while(nxt<=n)
        {
            int cur=0,mn=1;
            while(cur<mn&&nxt<=n)
                cur++,
                mn=b[nxt],
                nxt++;
            if(cur>=mn)
                ans++;
        }
        cout<<ans<<"\n";
    }
}