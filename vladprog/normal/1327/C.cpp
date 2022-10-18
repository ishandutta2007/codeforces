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

    int n,m;
    cin>>n>>m;
    cout<<(n-1)+(m-1)+n*m<<"\n";
    cout<<string(n-1,'U');
    cout<<string(m-1,'L');
    for(int j=1;j<=m;j++)
    {
        if(j%2==1)
            cout<<string(n-1,'D');
        else
            cout<<string(n-1,'U');
        cout<<'R';
    }
}