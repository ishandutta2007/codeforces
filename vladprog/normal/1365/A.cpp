#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=55;

int r[N],c[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            r[i]=0;
        for(int j=1;j<=m;j++)
            c[j]=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                int a;
                cin>>a;
                if(a)
                    r[i]=c[j]=1;
            }
        int x=0;
        for(int i=1;i<=n;i++)
            if(!r[i])
                x++;
        int y=0;
        for(int j=1;j<=m;j++)
            if(!c[j])
                y++;
        cout<<(min(x,y)%2?"Ashish":"Vivek")<<"\n";
    }
}