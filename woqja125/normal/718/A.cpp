#include<stdio.h>
char s[200010];
int main()
{
	int n, t, i;
	s[0] = '0';
	scanf("%d%d%s", &n, &t, s+1);
	for(i=0; s[i]!='.'; i++);

	for(; s[i] < '5' && s[i]!=0; i++);
	for(;s[i] != 0 && t>0;i--)
	{
		if(s[i] < '5' || s[i] == '.') break;
		t--;
		s[i] = 0;
		int j=i-1;
		if(s[j] == '.') j--;
		for(; j>=0;)
		{
			s[j]++;
			if(s[j] <= '9') break;
			s[j] = '0';
			if(s[j-1] == '.') j-=2;
			else j--;
		}
	}

	for(i=0; s[i]; i++);
	if(s[i-1] == '.') s[i-1] = 0;
	if(s[0] == '0') printf("%s", s+1);
	else printf("%s", s);
	return 0;
}