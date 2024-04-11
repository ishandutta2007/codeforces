#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e6+100;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int cnt[9]={};
    for(int i=1;i<=n;i++)
        cnt[i%9]++;
    int ans=0;
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
            for(int k=0;k<9;k++)
                if(i*j%9==k)
                    ans+=cnt[i]*cnt[j]*cnt[k];
    for(int a=1;a<=n;a++)
        ans-=n/a;
    cout<<ans;
}