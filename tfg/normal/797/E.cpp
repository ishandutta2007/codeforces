
 #include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <ctime>
using namespace std;
const int N=100005;

int n,q;
int a[N];
int dp[340][N];
bool vis[N];

int simulate(int p,int k)
{
    int ans=0;

    while(p<=n)
    {
        p=p+a[p]+k;
        ans++;
    }
    return ans;
}

void precompute(int k)
{

    vector <int> v;
    int i,j,p,ans;

    for(i=n;i>0;i--)
    {
      if(i + a[i] + k > n)
        dp[k][i] = 1;
      else
        dp[k][i] = dp[k][i + a[i] + k] + 1;
    }
}

int main()
{
    int i;
    int p,k,r;
    int sqrtn=1;

    cin>>n;
    for(i=1;i<=n;i++)
     scanf("%d",&a[i]);

    while(sqrtn*sqrtn<=n)
        sqrtn++;
    for(i=1;i<=sqrtn;i++)
        precompute(i);

    cin>>q;
    for(i=1;i<=q;i++)
    {
        scanf("%d%d",&p,&k);
        if(k>sqrtn)

        {
            r=simulate(p,k);
            printf("%d\n",r);
        }
        else
            printf("%d\n",dp[k][p]);


    }



    return 0;
}