#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e5+100;

int a[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int j=35;j>=0;j--)
    {
        int cnt=0;
        for(int i=1;i<=n;i++)
            if((a[i]>>j)&1)
                cnt++;
        if(cnt==1)
        {
            for(int i=1;i<=n;i++)
                if((a[i]>>j)&1)
                    cout<<a[i]<<" ";
            for(int i=1;i<=n;i++)
                if(!((a[i]>>j)&1))
                    cout<<a[i]<<" ";
            exit(0);
        }
    }
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
}