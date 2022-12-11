#include <iostream>
using namespace std;

int main()
{
    int b[1001]={0},x,y,n,i,h[1001]={0};
    cin>>n;
    for (i=0;i<n;i++)
    {
        cin>>x>>y;
        if (x!=y) {b[y]=-1;if ((b[x]>=0)&&(h[x]==0)) b[x]++;} else
            {if (b[y]>=0) {if (h[y]==0) {h[y]=1;b[y]=1;} else b[y]=-1;}}
    }
    int ans=0;
    for(i=1;i<=1000;i++) if (b[i]>=0) ans+=b[i];
    cout<<ans;
}