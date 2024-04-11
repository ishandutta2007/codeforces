#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2010,D=10;

int lx[N][D],rx[N][D],ly[N][D],ry[N][D];

void mn(int&a,int b)
{
    a=min(a,b);
}
void mx(int&a,int b)
{
    a=max(a,b);
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
        int n;
        cin>>n;
        for(int d=0;d<D;d++)
            for(int i=0;i<=n;i++)
                lx[i][d]=ly[i][d]=n+1,
                rx[i][d]=ry[i][d]= -1;
        for(int i=1;i<=n;i++)
        {
            string s;
            cin>>s;
            s="_"+s;
            for(int j=1;j<=n;j++)
            {
                int d=s[j]-'0';
                mn(lx[j][d],i);
                mx(rx[j][d],i);
                mn(ly[i][d],j);
                mx(ry[i][d],j);
                mn(lx[0][d],i);
                mx(rx[0][d],i);
                mn(ly[0][d],j);
                mx(ry[0][d],j);
            }
        }
        for(int d=0;d<D;d++)
        {
            int ans=0;
            for(int i=1;i<=n;i++)
            {
                if(rx[i][d]!=-1)
                    mx(ans,(rx[i][d]-lx[i][d])*max(n-i,i-1)),
                    mx(ans,max(n-lx[i][d],rx[i][d]-1)*max(ry[0][d]-i,i-ly[0][d]));
                if(ry[i][d]!=-1)
                    mx(ans,(ry[i][d]-ly[i][d])*max(n-i,i-1)),
                    mx(ans,max(n-ly[i][d],ry[i][d]-1)*max(rx[0][d]-i,i-lx[0][d]));
            }
            cout<<ans<<" ";
        }
        cout<<"\n";
    }
}