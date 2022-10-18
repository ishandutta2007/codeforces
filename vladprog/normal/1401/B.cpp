#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

void op(int&a,int&b,int add,int&ans)
{
    int cnt=min(a,b);
    a-=cnt;
    b-=cnt;
    ans+=add*cnt;
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
        int x1,y1,z1,x2,y2,z2;
        cin>>x1>>y1>>z1>>x2>>y2>>z2;
        int ans=0;
        op(z1,y2,2,ans);
        op(y1,x2,0,ans);
        op(y1,y2,0,ans);
        op(x1,z2,0,ans);
        op(z1,z2,0,ans);
        op(y1,z2,-2,ans);
        cout<<ans<<"\n";
    }
}