#include <bits/stdc++.h>
using namespace std;
char gr[3][3];
bool ok()
{
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			if(gr[i][j]!=gr[2-i][2-j])
				return false;
	return true;
}
int main()
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			cin>>gr[i][j];
		}
	}
	if(ok())	cout<<"YES";
	else cout<<"NO";
	return 0;
}