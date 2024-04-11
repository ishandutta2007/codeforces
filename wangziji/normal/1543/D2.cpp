#include <bits/stdc++.h>
using namespace std;
int K[50],b[50];
int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int n,k;
		cin >> n >> k;
		for(int i=0;i<=30;i++)
		    K[i]=1,b[i]=0;
		for(int i=0;i<n;i++)
		{
			int c[50]={},qwq=i;
			for(int j=0;j<=30;j++)
				c[j]=qwq%k,qwq/=k;
			int ans=0,now=1;
			for(int j=0;j<=30;j++)
			{
				if(now>2e7) break;
			    int x=((K[j]*c[j]+b[j])%k+k)%k;
				ans+=now*x;
				b[j]-=x;
				now*=k;
			}
	    	cout << ans << endl;
	    	int t;
	    	cin >> t;
	    	if(t==1) break;
	    	for(int j=0;j<=30;j++)
	    	{
	    		K[j]=-K[j],b[j]=-b[j];
	    		b[j]%=k;
			}
		}
	}
	return 0;
}