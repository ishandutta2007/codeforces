#include <iostream>
using namespace std;
int dep[1005][12],a[1005][1005];
int n,k,cnt;
int main(int argc, char** argv) {
	cin >> n >> k;
	int qwq=1,m=0;
	while(qwq<n) qwq*=k,++m;
	--k;
	cnt=n;
	cout << m << "\n";
	for(int i=1;i<=n;i++)
	{
		int x=n-i;
		for(int j=1;j<=m;j++)
		{
			dep[i][j]=x%(k+1);
			x/=k+1;
	//		cout << dep[i][j] << " ";
		}
	//	cout << "*\n";
	}
	for(int i=n;i>=1;i--)
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int x=1;x<=m;x++)
			{
				if(dep[j][x]+1<=dep[i][x])
				{
			//		cout << i << "lala" << j << "\n";
					a[i][j]=x;
					break;
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
			cout << a[i][j] << " ";
	}
	return 0;
}