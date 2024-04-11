#include <bits/stdc++.h>
using namespace std;
int dp[505][505];
signed main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		string a,b;
		cin >> a >> b;
		string B=b;
		int n=a.size(),m=b.size();
		a=' '+a+' ';
		b='*'+b+'*';
		int flag=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				string s="";
				for(int k=i;k<=j;k++) s+=a[k];
				for(int k=j-1;k>0;k--)
				{
					if(s.size()<B.size()) s+=a[k];
				}
				if(s==B) flag=1;
			}
		}
		if(flag) cout << "YES\n";
		else puts("NO");
	}
	return 0;
}