#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

typedef long double ld;
const ld one=1;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e6+100;

int ans[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,q;
    cin>>n>>q;
    int d1=0,d2=0;
    while(q--)
    {
        int t;
        cin>>t;
        if(t==1)
        {
            int x;
            cin>>x;
            d1+=x;
            d2+=x;
        }
        else
            if(d1%2)
                d1--,d2++;
            else
                d1++,d2--;
    }
    for(int i=1;i<=n;i++)
        ans[((i+(i%2?d1:d2))%n+n-1)%n+1]=i;
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<" ";
}