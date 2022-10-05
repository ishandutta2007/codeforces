#include <bits/stdc++.h>
using namespace std;
string str;
int n,vis[30],pnt,ans=0x3f3f3f3f;
bool gg(int N)
{
	for(int i=1;i<=26;i++)
		if(vis[i]>N/2) return true;
	return false;
}
int main()
{
	scanf("%d",&n);
	cin>>str;
	int pnt=0;
	for(int i=0;i<n;i++)
	{
		memset(vis,0,sizeof(vis));
		for(int j=i;j<n;j++)
		{
			vis[str[j]-'a'+1]++;
			if(!gg(j-i+1)) 
			{
				printf("YES\n");
				for(int k=i;k<=j;k++)
					printf("%c",str[k]);
				return 0;
			}
		}
	}
	printf("NO\n");
	return 0;
}