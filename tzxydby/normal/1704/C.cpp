#include<bits/stdc++.h>
using namespace std;
void sol()
{
	int n,m;
	vector<int>a,v;
	scanf("%d%d",&n,&m);
	a.resize(m);
	for(int i=0;i<m;i++)
	{
		scanf("%d",&a[i]);
		a[i]--;
	}
	sort(a.begin(),a.end());
	if(a.size()==1)
		v.push_back(n-1);
	else
	{
		for(int i=0;i<a.size();i++)
		{
			int pl=a[i],pr=(a[(i+1)%a.size()]);
			if((pl+1)%n!=pr)
				v.push_back((pr-pl-1+n)%n);
		}
	}
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	int g=0,s=0;
	for(int i=0;i<v.size();i++)
	{
		if(v[i]<=g)
			break;
		s+=max(1,v[i]-g-1);
		g+=4;
	}
	printf("%d\n",n-s);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}