#include<bits/stdc++.h>

typedef long long ll;
#define int ll
typedef long double ld;

using namespace std;

const int X=4e5+100;

int cnt[X];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int q,x;
    cin>>q>>x;
    int m=0;
    while(q--)
    {
        int y;
        cin>>y;
        cnt[y%x]++;
        while(cnt[m%x]>m/x)
            m++;
        cout<<m<<"\n";
    }
}