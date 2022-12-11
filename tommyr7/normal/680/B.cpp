#include <bits/stdc++.h>
using namespace std;
int t[107],n,a;
int main()
{
    cin>>n>>a;
    memset(t,0,sizeof(t));
    for (int i=1;i<=n;i++) cin>>t[i];
    int ans=0;
    if (t[a]>0) ++ans;
    for (int dis=1;dis<=n;dis++)
    {
        int left=a-dis,right=a+dis;
        int sum=0;
        if (left>=1&&t[left]>0) ++sum;
        if (right<=n&&t[right]>0) ++sum;
        if (sum==2) ans+=2;
        if ((left<=0||right>n)&&sum==1) ans+=1;
    }
    cout << ans << endl;
    return 0;
}