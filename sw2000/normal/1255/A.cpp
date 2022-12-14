#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
const int inf=0x3f3f3f3f;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        a=abs(a-b);
        int ans=a/5;
        a%=5;
        if(a==1||a==2)ans+=1;
        if(a==3||a==4) ans+=2;
        printf("%d\n",ans);
    }
    return 0;
}