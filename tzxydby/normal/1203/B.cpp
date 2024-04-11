#include<bits/stdc++.h>
using namespace std;
const int N=10005;
int a[N];
vector<int>v;
int main()
{
	int q;
	scanf("%d",&q);
	while(q--) 
	{
		memset(a,0,sizeof(a));
		v.clear();
		int n;
		scanf("%d",&n);
		n*=4;
		for(int i=1;i<=n;i++)
		{
			int x;
			scanf("%d",&x);
			a[x]++;
		}
		for(int i=1;i<=10000;i++)
		{
			while(a[i]>=2)
			{
				v.push_back(i);
				a[i]-=2;
			}
		}
		int m=v.size(),flag=1;
		if(m*2!=n)
			flag=0;
		for(int i=0;i<m;i++)
			if(v[i]*v[m-i-1]!=v[0]*v[m-1])
				flag=0;
		puts(flag?"YES":"NO");
	}
	return 0;
}