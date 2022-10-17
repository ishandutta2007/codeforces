#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define forii for(int i=1;i<=n;++i)
#define forji for(int j=1;j<=n;++j)
#define forjj for(int j=1;j<=m;++j)
#define forij for(int i=1;i<=m;++i)

int main()
{
    int n,d;
    cin>>n>>d;
    int m;
    cin>>m;
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        if(x+y<d || x+y>2*n-d || y-x>d || x-y>d) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
}