#include<bits/stdc++.h>
using namespace std;
const int N=5005;
const int mod=998244353;
long long s[N][N];
int main()
{
	for(int i=0;i<=5000;i++)
	{
		for(int j=0;j<=5000;j++)
		{
			if(i==0||j==0)
				s[i][j]=1;
			else
				s[i][j]=(s[i-1][j]+j*s[i-1][j-1])%mod;
		}
	}
	long long a,b,c;
	cin>>a>>b>>c;
	cout<<s[a][b]*s[b][c]%mod*s[a][c]%mod<<endl; 
	return 0;
}