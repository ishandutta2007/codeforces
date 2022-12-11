#include <stdio.h>

char line[100005];
int cnt[105];

int main()
{
	int n;
	scanf("%d ", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d ",&cnt[i]);
	}

	for (int i = 0; i < n; i++)
	{
		fgets(line,100005,stdin);
		for (int j = 0; line[j]; j++)
		{
			if(line[j]=='a'||line[j]=='e'||line[j]=='i'||
				line[j]=='o'||line[j]=='u'||line[j]=='y') cnt[i]--;
		}
		if (cnt[i])
		{
			printf("NO");
			return 0;
		}
	}
	printf("YES");
}