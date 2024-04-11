#pragma GCC optimize("O3")
#include <bits/stdc++.h>

typedef long long ll;
#define int ll
typedef long double ld;

using namespace std;

const int N=2e4+100,M=60;

bitset<N> b[M];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int m,n;
    cin>>m>>n;
    for(int i=0;i<m;i++)
    {
        int k;
        cin>>k;
        while(k--)
        {
            int x;
            cin>>x;
            b[i].set(x-1);
        }
    }
    for(int i=0;i<m;i++)
        for(int j=i+1;j<m;j++)
            if((b[i]&b[j]).none())
                cout<<"impossible",exit(0);
    cout<<"possible";
}