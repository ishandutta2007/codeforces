#include<bits/stdc++.h>
using namespace std;
const int N=2005;
int yly[N];
char a[N],b[N],c[N];
vector<int>x,y;
vector<long long>anss;
int main()
{
	scanf("%s%s%s",a,b,c);
	int k=strlen(a),n=strlen(b),m=strlen(c),ans=1;
	long long sum;
	for(int i=0;i<k-n+1;i++)
		if(!strncmp(a+i,b,n))
			x.push_back(i);
	for(int i=0;i<k-m+1;i++)
		if(!strncmp(a+i,c,m))
			yly[i+m-1]=1;
	if(x.size()==0)
	{
		printf("0\n");
		return 0;
	}
	for(int i=0;i<x.size();i++)
	{
		sum=0;
		for(int j=x[i];j<k;j++)
		{
			sum=sum*257+a[j]-'a'+1;
			if(yly[j]&&j-x[i]+1>=max(n,m)&&j-m+1>=x[i])
			{
				anss.push_back(sum);	
				//printf("%d %d %d\n",x[i],j,sum);
			}
		}
	}
	if(!anss.size())
		ans--;
	sort(anss.begin(),anss.end());
	for(int i=1;i<anss.size();i++)
		if(anss[i]!=anss[i-1])
			ans++;
	//for(int i=0;i<anss.size();i++)
		//printf("%d ",anss[i]);
	printf("%d\n",ans);
	return 0;
}