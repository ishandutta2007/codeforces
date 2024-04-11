#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=110;

string s[N];

vector<array<int,6>> ans;

void op(int x1,int y1,int x2,int y2,int x3,int y3)
{
    ans.push_back({x1,y1,x2,y2,x3,y3});
    s[x1][y1]='0'+('1'-s[x1][y1]);
    s[x2][y2]='0'+('1'-s[x2][y2]);
    s[x3][y3]='0'+('1'-s[x3][y3]);
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
        ans.clear();
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            cin>>s[i],
            s[i]="_"+s[i];
        for(int i=1;i<=n;i+=2)
        {
            if(i==n)
                i--;
            for(int j=1;j<=m-2;j++)
            {
                if(s[i][j]=='1')
                    if(s[i+1][j]=='1')
                        op(i,j,i+1,j,i,j+1);
                    else
                        op(i,j,i,j+1,i+1,j+1);
                else
                    if(s[i+1][j]=='1')
                        op(i+1,j,i,j+1,i+1,j+1);
            }
        }
        for(int i=m-1;i<=m;i+=2)
        {
            if(i==m)
                i--;
            for(int j=1;j<=n-2;j++)
            {
                if(s[j][i]=='1')
                    if(s[j][i+1]=='1')
                        op(j,i,j,i+1,j+1,i);
                    else
                        op(j,i,j+1,i,j+1,i+1);
                else
                    if(s[j][i+1]=='1')
                        op(j,i+1,j+1,i,j+1,i+1);
            }
        }
        bool inv[2][2]={};
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                if(s[n-i][m-j]=='1')
                    for(int x=0;x<2;x++)
                        for(int y=0;y<2;y++)
                            if(i==x||j==y)
                                inv[x][y]=!inv[x][y];
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                if(inv[i][j])
                {
                    vector<int> cur;
                    for(int x=0;x<2;x++)
                        for(int y=0;y<2;y++)
                            if(i==x||j==y)
                                cur.push_back(n-x),
                                cur.push_back(m-y);
                    op(cur[0],cur[1],cur[2],cur[3],cur[4],cur[5]);
                }
        cout<<ans.size()<<"\n";
        for(auto arr:ans)
            cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<" "<<arr[3]<<" "<<arr[4]<<" "<<arr[5]<<"\n";
//        for(int i=1;i<=n;i++)
//            cout<<s[i].substr(1)<<"\n";
    }
}