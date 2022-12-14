#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 10;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;

int main()
{
    string a,b;
    cin>>a>>b;
    int la=a.length(),lb=b.length(),ans=0,cnt=0,yes,flag=0;
    for(int i=0;i<lb;i++)
    {
        if(b[i]!=a[i])cnt++;
    }
    if(cnt%2)yes=0;
    else yes=1;

    for(int i=1;i<lb;i++)
    {
        if(b[i]!=b[i-1])flag++;
    }
    flag%=2;
    ans=yes;

    for(int i=0;i<la-lb;i++)
    {
        cnt=0;
        if(a[i]!=b[0])cnt++;
        if(a[i+lb]!=b[lb-1])cnt++;

        if((cnt+flag)%2==1)yes=1-yes;
        ans+=yes;
    }

    cout<<ans;
    return 0;
}