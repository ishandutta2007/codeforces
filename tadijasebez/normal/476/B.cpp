#include <stdio.h>
#include <cstring>
char word[15];
int goal;
double Solve(int pos, int len, int sum)
{
	if(pos==len)
	{
		if(sum==goal) return 1;
		return 0;
	}
	double ans;
	if(word[pos]=='+')
	{
		ans=Solve(pos+1,len,sum+1);
	}
	else if(word[pos]=='-')
	{
		ans=Solve(pos+1,len,sum-1);
	}
	else
	{
		ans=(Solve(pos+1,len,sum+1)+Solve(pos+1,len,sum-1))/2;
	}
	return ans;
}
int main()
{
	int n,i;
	scanf("%s",&word);
	n=(unsigned) strlen(word);
	for(i=0;i<n;i++) goal+=word[i]=='+'?1:-1;
	scanf("%s",&word);
	printf("%.12llf\n",Solve(0,n,0));
	return 0;
}