#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	vector<string> Map(n);
	for(int i=0;i<n;++i)
		cin>>Map[i];
	vector<int> sum(m);
	for(int i=0;i+1<m;++i)
	{
		bool flag=true;
		for(int j=0;j+1<n;++j)
		{
			if(Map[j+1][i]=='X'&&Map[j][i+1]=='X')
			{
				flag=false;
				break;
			}
		}
		sum[i]=flag;
		if(i)
			sum[i]+=sum[i-1];
	}
	if(m>=2)
		sum[m-1]=sum[m-2];
	int q;
	cin>>q;
	while(q--)
	{
		int a,b;
		cin>>a>>b;
		--a,--b;
		if((b?sum[b-1]:0)-(a?sum[a-1]:0)==b-a)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}