#include <iostream>
using namespace std;
int a[10005],b[10005];
int main(int argc, char** argv) {
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=m;i++) cin >> b[i];
	int ans=1e9;
	for(int i=0;i<=1000;i++)
	{
		int F=1;
		for(int j=1;j<=n;j++)
		{
			int flag=0;
			for(int k=1;k<=m;k++)
			{
				if((a[j]&b[k]|i)==i)
					flag=1;
			}
			if(!flag) F=0; 
		}
		if(F)
		{
			cout << i;
			return 0;
		}
	}
	return 0;
}