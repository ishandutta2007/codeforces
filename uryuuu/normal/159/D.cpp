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
#define pii pair<int,int>
using namespace std;
const int maxn=2010;

ll f[maxn][maxn];
int main()
{
    sync
    ll k,l,len,sum[maxn];
    char s[maxn];
    cin>>s;
    len=strlen(s);
    mm(f);
    for(int i=0;i<len;i++)
    {
        f[i][i]=1;
    }
    for(int i=1;i<len;i++)
    {
        for(int j=0;j+i<len;j++)
        {
            k=i+j;
            if(s[j]==s[k])
            {
                if(i==1)
                    f[j][k]=1;
                else
                    f[j][k]=f[j+1][k-1];
            }
        }
    }
    mm(sum);
    for(int i=0;i<len;i++)
    {
        for(int j=i;j<len;j++)
        {
            sum[i]+=f[i][j];
        }
    }
    for(int i=0;i<len;i++)
    {
        for(int j=i+1;j<len;j++)
        {
            sum[i]+=sum[j];
        }
    }
    l=0;
    for(int i=0;i<len;i++)
        for(int j=i;j<len;j++)
        {
            if(f[i][j])
                l+=sum[j+1];
        }
    cout<<l<<endl;
    return 0;
}