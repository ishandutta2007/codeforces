#include <iostream>
#define int long long
using namespace std;
int qzh[30][100005];
signed main(int argc, char** argv) {
	string a;
	cin >> a;
	int n=a.size();
	a=' '+a;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=27;j++)
			qzh[j][i]=qzh[j][i-1]+(a[i]-'a'==j);
	}
	int ans=0;
	for(int i=0;i<=27;i++)
	{
		ans=max(ans,qzh[i][n]);
		for(int j=0;j<=27;j++)
		{
			int t=0;
			for(int k=1;k<=n;k++)
			{
				t+=(a[k]-'a'==i)*qzh[j][k-1];
			}
			ans=max(ans,t);
		}
	}
	cout << ans;
	return 0;
}