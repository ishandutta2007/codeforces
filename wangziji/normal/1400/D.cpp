#include <iostream>
using namespace std;
int a[5005],qzh[3005][3005];
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				qzh[i][j]=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
				if(a[i]==a[j]) ++qzh[i][j];
		}
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
				qzh[i][j]+=qzh[i][j-1]+qzh[i-1][j]-qzh[i-1][j-1];
		}
		for(int i=1;i<n;i++)
		{
			for(int j=i+2;j<n;j++)
			{
				if(a[i]==a[j])
				{
					ans+=qzh[j-1][n];
					ans-=qzh[i][n];
					ans-=qzh[j][j];
					ans+=qzh[i][j];
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}