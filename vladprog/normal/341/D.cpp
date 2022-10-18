#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;
#define int ll

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1010;

int t[4][N][N];

int col(int x,int y)
{
    return ((x&1)<<1)|(y&1);
}

int sum(int x,int y)
{
    int c=col(x,y);
    int res=0;
    for(int i=x;i>=0;i=(i&(i+1))-1)
        for(int j=y;j>=0;j=(j&(j+1))-1)
            res^=t[c][i][j];
    return res;
}

void upd(int x,int y,int val)
{
    int c=col(x,y);
    for(int i=x;i<N;i|=i+1)
        for(int j=y;j<N;j|=j+1)
            t[c][i][j]^=val;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;
    while(m--)
    {
        int t,x1,y1,x2,y2;
        cin>>t>>x1>>y1>>x2>>y2;
        if(t==1)
            cout<<(sum(x2,y2)^
                   sum(x2,y1-1)^
                   sum(x1-1,y2)^
                   sum(x1-1,y1-1))<<"\n";
        else
        {
            int val;
            cin>>val;
            upd(x1,y1,val);
            upd(x1,y2+1,val);
            upd(x2+1,y1,val);
            upd(x2+1,y2+1,val);
        }
    }
}