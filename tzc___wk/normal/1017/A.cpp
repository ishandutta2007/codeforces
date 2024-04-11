#include <bits/stdc++.h>
using namespace std;
struct id
{
	int a,b,c,d,w,sum;
};
id s[1100];
int sum[1100];
bool cmp(id a,id b)
{
	if(a.sum!=b.sum)	return a.sum>b.sum;
	return a.w<b.w;
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>s[i].a>>s[i].b>>s[i].c>>s[i].d;
		s[i].sum=s[i].a+s[i].b+s[i].c+s[i].d;
		s[i].w=i-1;
	}
	int m=s[0].sum;
	sort(s,s+n,cmp);
	for(int i=0;i<n;i++)
	{
		if(s[i].sum==m)
		{
			cout<<i+1<<endl;
			return 0;
		}
	}
}