#include <stdio.h>
#include <cstring>
const int N=1005;
char word[N];
int ask()
{
	printf("? %s\n",word);
	fflush(stdout);
	int ans;
	scanf("%i",&ans);
	fflush(stdout);
	return ans;
}
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=0;i<n;i++) word[i]='1';
	word[n]=0;
	int tmp1=ask();
	word[0]='0';
	int tmp2=ask();
	if(tmp1>tmp2)
	{
		//First Element Is 0
		int top=n;
		int bot=1;
		int mid,sol;
		while(top>=bot)
		{
			mid=top+bot>>1;
			for(i=0;i<mid;i++) word[i]='0';
			for(i=mid;i<n;i++) word[i]='1';
			tmp2=ask();
			if(tmp2==tmp1-mid) bot=mid+1;
			else sol=mid,top=mid-1;
		}
		printf("! %i %i\n",1,sol);
		fflush(stdout);
	}
	else
	{
		//First Element Is 1
		for(i=0;i<n;i++) word[i]='0';
		tmp1=ask();
		int top=n;
		int bot=1;
		int mid,sol;
		while(top>=bot)
		{
			mid=top+bot>>1;
			for(i=0;i<mid;i++) word[i]='1';
			for(i=mid;i<n;i++) word[i]='0';
			tmp2=ask();
			if(tmp2==tmp1-mid) bot=mid+1;
			else sol=mid,top=mid-1;
		}
		printf("! %i %i\n",sol,1);
		fflush(stdout);
	}
	return 0;
}