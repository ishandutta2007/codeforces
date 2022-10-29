#include <iostream>
#include <map>
#include <cstring>
using namespace std;
int dp[10005];
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int q,d;
		cin >> q >> d;
		memset(dp,0,sizeof dp);
		dp[0]=1;
		for(int i=0;i<=2000;i++)
		{
			for(int j=1;j<=2000;j++)
				if(j%10==d||j/10%10==d||j/100%10==d||j/1000==d) dp[i+j]|=dp[i];
		}
		while(q--)
		{
			int x;
			cin >> x;
			if(x>2000||dp[x])
			{
				puts("YES");
			}else puts("NO");
		}
	}
	return 0;
}