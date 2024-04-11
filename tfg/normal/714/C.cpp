#include <bits/stdc++.h>

int i_m[(1<<19) + 10];
int n;
std::string ot_str;
int value()
{
	int ans=0;
	for(int i=0;i<(int)ot_str.size();i++)
	{
		ans=ans<<1;
		ans+=(ot_str[i]-'0')%2==0?0:1;
	}
	return ans;
}

int main()
{
	scanf("%i", &n);
	for(int i=0;i<n;i++)
	{
		char str[4];scanf(" %s", str);
		std::cin >> ot_str;
		//printf("%i:%c and %s\n",i,str[0],ot_str.c_str());
		if(str[0]=='+')
		{
			i_m[value()]++;
		}
		else if(str[0]=='-')
		{
			i_m[value()]--;
		}
		else
		{
			printf("%i\n",i_m[value()]);
		}
	}
}