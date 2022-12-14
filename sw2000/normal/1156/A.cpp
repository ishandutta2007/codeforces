#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 100010;
int main()
{
    int n,ans=0,a[110]={0};
    cin>>n;
    for(int i=3;i<n+3;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]+a[i-1]==5)
        {
            cout<<"Infinite"<<endl;
            return 0;
        }

        if(a[i]==1)
        {
            if(a[i-1]==3)ans+=4;
            if(a[i-1]==2)ans+=3;
        }
        if(a[i]==2)
        {
            if(a[i-1]==1)ans+=3;
            if(a[i-2]==3)ans-=1;

        }
        if(a[i]==3)
        {
            if(a[i-1]==1)ans+=4;
        }
    }
    cout<<"Finite"<<endl<<ans;
    return 0;
}