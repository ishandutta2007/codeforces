#include <bits/stdc++.h>
using namespace std;
long long zero,one,n,x,y;
bool now,str[300005];
int main()
{
	scanf("%d%d%d",&n,&x,&y);
	getchar();
	for(int i=1;i<=n;i++)
	{
		char ch;
		scanf("%c",&ch);
		if(ch=='0') str[i]=0;
		else str[i]=1;
	}
	now=-1; 
	for(int i=1;i<=n;i++)
		if(str[i]==0&&now!=0){zero++;now=0;}
		else if(str[i]==1&&now!=1){one++;now=1;}
if(!zero) {printf("0");return 0;}
	printf("%I64d",min((zero-1)*x+y,zero*y));
	return 0;
}