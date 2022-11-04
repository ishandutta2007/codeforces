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
const ll Mod=1e9+7;
#define maxn 2000
using namespace std;
int dd[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int a[maxn],isprime[maxn];
void primetable()
{
    int i,j;
    memset(isprime,1,sizeof(isprime));
    isprime[0]=isprime[1]=0;
    int max=sqrt(maxn*1.0);
    for(i=2; i<=max; i++)
    {
        if(isprime[i])
        {
            for(j=2; j*i<=maxn; j++)
                isprime[i*j]=0;
        }
    }
}
int main()
{
    primetable();
    int n;
    cin>>n;
    if(isprime[n])
    {
        cout<<n<<endl;
        for(int i=1;i<=n;i++)
        {
            cout<<i<<' '<<(i%n)+1<<endl;
        }
    }
    else
    {
        int k=n;
        for(;k<2000;k++)
        {
            if(isprime[k])
                break;
        }
        cout<<k<<endl;
        for(int i=1;i<=n;i++)
        {
            cout<<i<<' '<<(i%n)+1<<endl;
        }
        for(int i=1;i<k-n+1;i++)
        {
             cout<<i<<' '<<(n-i+n)%n<<endl;
        }
    }
    return 0;
}