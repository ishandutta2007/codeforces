#include<bits/stdc++.h>
using namespace std;
int n;
char s[100005];
bool del[100005];
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	int x=n-11;
	x/=2;
	int l=1,r=1;
	for(int i=1;i<=x;++i)
	{
		while(l<=n&&s[l]=='8')l++;
		if(l<=n)del[l]=1,l++;
		while(r<=n&&s[r]!='8')r++;
		if(r<=n)del[r]=1,r++;
	}
	for(int i=1;i<=n;++i)if(!del[i])
	{
		if(s[i]=='8')puts("YES");
		else puts("NO");
		break;
	}
	return 0;
}