#include<stdio.h>
#include<map>
char a[10], b[100];
int main()
{
	int n;
	scanf("%d", &n);
	std::map<int, int> M;
	for(int i=1; i<=n; i++)
	{
		scanf("%s%s", a, b);
		int t = 0;
		for(int j=0; b[j]; j++) t = t*2+((b[j]-'0')%2);
		if(a[0] == '+')
		{
			if(M.count(t) == 0) M[t] = 1;
			else M[t]++;
		}
		else if(a[0] == '-')
		{
			M[t]--;
		}
		else
		{
			printf("%d\n", M[t]);
		}
	}
	return 0;
}