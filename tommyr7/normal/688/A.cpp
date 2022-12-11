#include <bits/stdc++.h>
using namespace std;
int n,d,ans,now;
int main()
{
    cin>>n>>d;
    ans=0,now=0;
    for (int i=1;i<=d;i++)
    {
        bool flag=false;
        for (int j=1;j<=n;j++)
        {
            char ch=getchar();
            while (ch!='1'&&ch!='0') ch=getchar();
            if (ch=='0') flag=true;
        }
        if (flag) ++now; else now=0;
        if (now>ans) ans=now;
    }
    cout << ans <<endl;
    return 0;
}