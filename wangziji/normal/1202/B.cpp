#include <iostream>
#include <cstring>
#define mod 10
using namespace std;
int ans[15][15][15],cnt[100];
int main(int argc, char** argv) {
	string a;
	ios::sync_with_stdio(false);
	memset(ans,2,sizeof ans);
	for(int i=0;i<=9;i++)
	{
		for(int j=0;j<=9;j++)
		{
			ans[i][j][i]=ans[i][j][j]=1;
			for(int k=1;k<=100;k++)
			{
				for(int l=0;l<=9;l++)
				{
					ans[i][j][(l+i)%mod]=min(ans[i][j][(l+i)%mod],ans[i][j][l]+1);
					ans[i][j][(l+j)%mod]=min(ans[i][j][(l+j)%mod],ans[i][j][l]+1);
				}
			}
		}
	}
	cin >> a;
	for(int i=1;i<a.size();i++)
		++cnt[(a[i]-a[i-1]+mod)%mod];
	for(int i=0;i<=9;i++)
	{
		for(int j=0;j<=9;j++)
		{
			int ANS=0;
			for(int k=0;k<=9;k++)
			{
				if(cnt[k]&&ans[i][j][k]>1000)
					ANS=-1e9;
				else ANS+=cnt[k]*ans[i][j][k];
			}
			if(ANS<0) cout << -1 << " ";
			else cout << ANS-a.size()+1 << " ";
		}
		cout << endl;
	}
	return 0;
}