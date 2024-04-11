#include<bits/stdc++.h>
using namespace std;
int n,c,d;
vector<int>f,g;
void sol()
{
	scanf("%d",&n);
	f.resize(n);
	for(int i=0;i<n;i++)
		scanf("%d",&f[i]);
	c=0;
	for(int i=1;i<n;i++)
	{
		if(!f.size())
			break;
		d=c;
		g.clear();
		for(int j=0;j+1<f.size();j++)
		{
			if(f[j]==f[j+1])
				d++;
			else
				g.push_back(f[j+1]-f[j]);
		}
		if(c)
			g.push_back(f[0]),d--;
		sort(g.begin(),g.end());
		c=d;
		f=g;
	}	
	printf("%d\n",f.size()?f[0]:0);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}