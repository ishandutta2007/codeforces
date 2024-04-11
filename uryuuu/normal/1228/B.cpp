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
using namespace std;
const int maxn=200005;

long long Mode(long long a, long long b, long long mode)
{
    long long sum = 1;
    while (b) {
        if (b & 1) {
            sum = (sum * a) % mode;
            b--;
        }
        b /= 2;
        a = a * a % mode;
    }
    return sum%mode;
}

int a[1005][1005],r,c;
int main()
{
    sync
    int f=0;
    int h,w;
    cin>>h>>w;
    for(int i=1;i<=h;i++)
    {
        cin>>r;
        for(int j=1;j<=r;j++)
            a[i][j]=2;
        a[i][r+1]=1;
    }
    for(int i=1;i<=w;i++)
    {
        cin>>c;
        for(int j=1;j<=c;j++)
        {
            if(a[j][i]==1)
                f=1;
            a[j][i]=2;
        }
        if(a[c+1][i]==2)
        {
            f=1;
            break;
        }
        a[c+1][i]=1;
    }
    int s=0;
    for(int i=1;i<=h;i++)
        for(int j=1;j<=w;j++)
            if(a[i][j]==0)
                s++;
    if(f)
        cout<<0<<endl;
    else 
    cout<<(ll)Mode(2,s,1000000007)<<endl;
    return 0;
}