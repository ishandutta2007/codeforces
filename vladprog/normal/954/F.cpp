#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

const int N=1e4+100,MOD=1e9+7;

pair<int,int> events[2*N];

typedef array<int,3> row;
typedef array<row,3> matr;

matr mult(matr x,matr y)
{
    matr res{row{0,0,0},
             row{0,0,0},
             row{0,0,0}};
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            for(int k=0;k<3;k++)
                res[i][k]=(res[i][k]+x[i][j]*y[j][k])%MOD;
    return res;
}

matr ppow(matr x,int y)
{
    matr res{row{1,0,0},
             row{0,1,0},
             row{0,0,1}};
    while(y)
    {
        if(y&1)
            res=mult(res,x);
        y>>=1;
        x=mult(x,x);
    }
    return res;
}

void print(matr x)
{
    for(int i=0;i<3;i++,cout<<"\n")
        for(int j=0;j<3;j++)
            cout<<x[i][j]<<" ";
    cout<<"\n";
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;
    events[0]={2,0};
    for(int i=1;i<=n;i++)
    {
        int a,l,r;
        cin>>a>>l>>r;
        events[2*i-1]={l,a};
        events[2*i]={r+1,-a};
    }
    events[2*n+1]={m+1,0};
    int cnt[4]={};
    matr res{row{1,0,0},
             row{0,1,0},
             row{0,0,1}};
    sort(events,events+2*n+2);
//    print(res);
    for(int i=0;i<=2*n;i++)
    {
        if(events[i].second>0)
            cnt[events[i].second]++;
        else
            cnt[-events[i].second]--;
        matr cur{row{0,0,0},
                 row{0,0,0},
                 row{0,0,0}};
        if(!cnt[1])
            cur[0][0]=cur[1][0]=1;
        if(!cnt[2])
            cur[0][1]=cur[1][1]=cur[2][1]=1;
        if(!cnt[3])
            cur[1][2]=cur[2][2]=1;
        res=mult(res,ppow(cur,events[i+1].first-events[i].first));
//        print(cur);
//        cout<<(events[i+1].first-events[i].first)<<"\n\n";
//        print(res);
    }
    cout<<res[1][1];
}