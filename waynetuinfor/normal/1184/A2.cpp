#include<bits/stdc++.h>
using namespace std;
char s[212345];
int a[212345];
int main()
{
	int n;
	scanf("%d",&n);
	cin >> s;
	for(int i = 1;i<=n;i++)
	{
		if(n%i==0)
		{
			int flag = 1;
			for(int j = 0;j<i;j++) 
			{
				int cnt = 0;
				for(int k = 0;k*i<n;k++) if(s[i*k+j]=='1') cnt++;
				if(cnt%2) flag = 0;
				if(!flag) break;		
			}
			a[i] = flag;
		}
	}
	int ans = 0;
	for(int i = 1;i<n;i++) if(a[__gcd(i,n)]) ans++;
	int flag = 0;
	for(int i = 0;i<n;i++) if(s[i]=='1') flag = 1;
	printf("%d\n",ans+1-flag);
	return 0;
}