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

    int n,m,p;
    cin>>n>>m>>p;
    int x=0,y=0;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        if(a%p)
            x=i;
    }
    for(int i=0;i<m;i++)
    {
        int b;
        cin>>b;
        if(b%p)
            y=i;
    }
    cout<<x+y;
}