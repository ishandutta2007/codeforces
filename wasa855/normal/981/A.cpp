#include<bits/stdc++.h>
using namespace std;
char a[55];
bool judge(int l,int r)
{
	for(int i=0;i<=(r-l)/2;i++)
	{
		if(a[l+i]!=a[r-i])
		{
			return false;
		}
	}
	return true;
}
int main()
{
	scanf("%s",a);
	int maxn=0;
	int m=strlen(a);
	for(int i=0;i<m;i++)
	{
		for(int j=1;j<m-i;j++)
		{
			if(judge(i,i+j)==false)
			{
				maxn=max(maxn,j+1);
			}
		}
	}
	cout<<maxn<<endl;
	return 0;
}