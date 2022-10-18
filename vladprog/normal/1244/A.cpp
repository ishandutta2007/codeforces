#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;
typedef pair<int,int> pii;
#define x first
#define y second

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c,d,k;
        cin>>a>>b>>c>>d>>k;
        int x=(a+c-1)/c;
        int y=(b+d-1)/d;
        if(x+y>k)
            cout<<-1<<"\n";
        else
            cout<<x<<" "<<y<<"\n";
    }
}