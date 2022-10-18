#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
int tmp[1005];
int a[1005];
bool judge(int x)
{
    for(int i=1;i<=x;i++)
    {
        tmp[i]=a[i];
    }
    sort(tmp+1,tmp+x+1);
    int use=0;
    for(int i=x;i>0;i-=2)
    {
        use+=tmp[i];
    }
    return use<=k;
}
signed main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        scanf("%I64d",&a[i]);
    }
    for(int i=1;i<=n;i++)
    {
        if(judge(i)==false)
        {
            cout<<i-1<<endl;
            return 0;
        }
    }
    cout<<n<<endl;
    return 0;
}