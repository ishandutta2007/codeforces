#include <cstdio>
#include <algorithm>

char str[1000];

int endof(int x)
{
	for(;str[x]!='(' && str[x]!=')' && str[x]!='_' && str[x]!='\0';x++);
	return x;
}

int main()
{
	int n;
	scanf("%i", &n);
	scanf(" %s", str);
	int left=0, inside=0, max=0, pa=0;
	while(left<n)
	{
		while(str[left]=='(' || str[left]==')' || str[left]=='_')
		{
			if(str[left]=='(')
				pa++;
			if(str[left]==')')
				pa--;
			left++;
		}
		int next=endof(left);
		if(pa>0) inside++;
		else max=std::max(max,next-left);
		left=next;
	}
	printf("%i %i\n",max,inside);
}