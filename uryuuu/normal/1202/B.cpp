#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<stack>
#include<set>
#include<map>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define maxn 1000100
using namespace std;
string s;
int d[15][15][15];
int sum[15][15];
void init()
{
    for(int i=0;i<13;i++)
    {
        for(int j=0;j<13;j++)
            for(int k=0;k<13;k++)
            d[i][j][k]=600;
    }
    d[0][0][0]=0;
    for(int i=0;i<=9;i++)
    {
        for(int j=0;j<=9;j++)
        {
            for(int u=0;u<=9;u++)
            {
                if(i==j)
                {
                    d[i][j][u]=0;
                    continue;
                }
                if(i==u)
                {
                    d[i][j][u]=0;
                    continue;
                }
                int k=i;
                if(i==0)
                    k+=10;
                for(;k<=300;k+=10)
                {
                    for(int q=1;q<=30;q++)
                    {
                        for(int w=0;w<=q;w++)
                        {
                            if(k==w*j+(q-w)*u)
                            {
                                d[i][j][u]=min(q,d[i][j][u]);
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
}
int main()
{
    sync
    cin>>s;
    init();
    int len=s.length();
    mm(sum);
    for(int k=1;k<len;k++)
    {
        int c=s[k]-s[k-1];
        if(c<0)
            c+=10;
//        cout<<c<<endl;
        for(int i=0;i<10;i++)
        {
            for(int j=i;j<10;j++)
            {
                if(sum[i][j]==-1)
                    continue;
                if(d[c][i][j]==600)
                {
                    sum[i][j]=-1;
                    continue;
                }
                sum[i][j]+=d[c][i][j];
                if(d[c][i][j])
                    sum[i][j]--;
            }
        }
    }
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            if(i<=j)
                cout<<sum[i][j]<<' ';
            else
                cout<<sum[j][i]<<' ';
        }
        cout<<endl;
    }
//    cout<<endl;
//    for(int i=0;i<10;i++)
//    {
//        for(int j=i;j<10;j++)
//            cout<<d[8][i][j]<<' ';
//        cout<<endl;
//    }
    return 0;
}