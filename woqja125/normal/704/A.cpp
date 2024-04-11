#include<stdio.h>
#include<set>
int l[300001];
std::set<int> d[300001];
int main()
{
	int n, q, c=0, e=0, b3 = 1;
	scanf("%d%d", &n, &q);
	for(int i=1; i<=q; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		if(a==1)
		{
			c++;
			l[++e] = b;
			d[b].insert(e);
			printf("%d\n", c);
		}
		else if(a==2)
		{
			for(auto x: d[b])
			{
				if(l[x] != -1)
				{
					l[x] = -1;
					c--;
				}
			}
			d[b].clear();
			printf("%d\n", c);
		}
		else
		{
			for(b3; b3<=b; b3++)
			{
				if(l[b3] != -1)
				{
					l[b3] = -1;
					c--;
				}
			}
			printf("%d\n", c);
		}
	}
	return 0;
}