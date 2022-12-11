#include<bits/stdc++.h>
using namespace std;
char a[6][2];
int main()
{
	int i,j;
	for(i=0;i<6;i++) scanf("%s",a[i]);
	for(i=1;i<6;i++)
		for(j=0;j<2;j++)
			if(a[i][j]==a[0][j])
			{
				cout<<"YES";
				return 0;
			}
	cout<<"NO";
	return 0;
}