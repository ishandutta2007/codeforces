#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,a;
	scanf("%d",&n);
	vector <int> q;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a);
		q.push_back(a);
	}
	int x1,x2,x3,x4;
	for(int i=1;i<n;i++)
	{
		x1 = min(q[i],q[i-1]);
		x2 = max(q[i],q[i-1]);
		for(int j=1;j<n;j++)
		{
			if(j != i)
			{
				x3 = min(q[j-1],q[j]);
				x4 = max(q[j-1],q[j]);
				if((x1<x3 && x3 < x2 && x2 < x4) || (x3<x1 && x1 < x4 && x4 < x2))
				{
					printf("yes\n");
					return 0;
				}
				
			}
 
		}
	}
	printf("no\n");
}