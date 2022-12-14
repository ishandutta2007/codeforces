#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int inf=0x3fff3fff;

int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        int n,x,ans=1,ma1=-1,ma2=-1;
        cin>>n>>x;
        for(int i=0;i<n;i++)
        {
            int a,b;
            cin>>a>>b;
            ma1=max(ma1,a);
            ma2=max(ma2,a-b);
        }
        x-=ma1;
        if(x>0)
        {
            if(ma2<=0)ans=-1;
            else
            {
                ans+=(x-1)/ma2+1;
            }
        }
        cout<<ans<<endl;
    }

	return 0;
}