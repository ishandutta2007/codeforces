#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int n;
vector<int>a;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,x;
		scanf("%d",&n);
		a.clear();
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&x);
			if(x==1)
				a.push_back(1);
			else
			{
				while(a.size()&&a.back()+1!=x)
					a.pop_back();
				if(a.size())
					a.back()++;
				else
					a.push_back(1);
			}
			
			printf("%d",a[0]);
			for(int i=1;i<a.size();i++)
				printf(".%d",a[i]);
			puts("");
		}
	}
	return 0;
}