#include <bits/stdc++.h>
using namespace std;
int t[10],ans,ans1;
int main()
{
    ans=0;
    for (int i=1;i<=5;i++) cin>>t[i];
    for (int i=1;i<=5;i++)
        for (int j=i+1;j<=5;j++)
            for (int k=j+1;k<=5;k++)
                if (t[i]==t[j]&&t[j]==t[k]&&t[i]*3>ans) ans=t[i]*3;
    for (int i=1;i<=5;i++)
        for (int j=i+1;j<=5;j++)
            if (t[i]==t[j]&&t[i]*2>ans) ans=t[i]*2;
    ans1=0;
    for (int i=1;i<=5;i++) ans1+=t[i];
    cout << ans1-ans<<endl;
    return 0;
}