#include<bits/stdc++.h>
#define rep(i,a,n) for(i=a;i<=n;i++)
#define maxn 5
#define pb push_back
using namespace std;
int n,k;
int main()
{
    int i,tmp,ans=0,cnt=0,dig=0;
    scanf("%d%d",&n,&k);
    tmp=n;
    if(n==0)
    {
        printf("%d\n",ans);
        return 0;
    }
    while(tmp)
    {
        if(tmp%10==0) cnt++;
        tmp/=10;
        dig++;
    }
    if(cnt<k)
    {
        ans=dig-1;
        printf("%d\n",ans);
        return 0;
    }
    tmp=n;
    cnt=0;
    while(tmp)
    {
        if(tmp%10==0) cnt++;
        else ans++;
        tmp/=10;
        if(cnt==k) break;
    }
    printf("%d\n",ans);
    return 0;
}