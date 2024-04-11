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
#include<sstream>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define tm(a,b,c) max(max(a,b),c)
#define inf 0x3f3f3f3f
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
using namespace std;
int a[105][105],d[105][105];
int p[1000005],b[1000005];
string s;
int main()
{
    sync
    int n;
    cin>>n;
    memset(d,inf,sizeof(d));
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        for(int j=1;j<=n;j++)
        {
            a[i][j]=s[j-1]-'0';
            if(a[i][j])
                d[i][j]=1;
        }
    }
    for(int i=1;i<=n;i++)
        d[i][i]=0;
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        cin>>p[i];
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(d[i][k]+d[k][j]<d[i][j])
                    d[i][j]=d[i][k]+d[k][j];
            }
        }
    int g,cnt=0,f;
//    for(int i=1;i<=n;i++)
//    {
//        for(int j=1;j<=n;j++)
//        {
////            if(d[i][j]==2)
////                cout<<i<<' '<<j<<endl;
//            cout<<a[i][j]<<' ';
//        }
//        cout<<endl;
//    }
    for(int i=0;i<m;i++)
    {
        f=0;
        for(int j=n+5;j>=1;j--)
        {
            g=i+j;
            if(g>=m)
                continue;
            if(d[p[i]][p[g]]==j)
            {
//                cout<<i<<' '<<g<<endl;
                b[cnt++]=p[i];
                i=g-1;
                f=1;
                break;
            }
        }
        if(f==0)
            b[cnt++]=p[i];
    }
    cout<<cnt<<endl;
    for(int i=0;i<cnt;i++)
        cout<<b[i]<<' ';
    cout<<endl;
    return 0;
}