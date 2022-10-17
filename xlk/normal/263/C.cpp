#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
vector<int>a[100020];
int n,m,x,y;
int v[100020];
int w[100020];
int s[100020];
int ooo=1e9;
int ok(int x)
{
	ooo++;
	for(int i:a[s[x]])
		v[i]=ooo;
	if(v[s[(x+1)%n]]!=ooo)
		return 0;
	if(v[s[(x+2)%n]]!=ooo)
		return 0;
	if(v[s[(x-1+n)%n]]!=ooo)
		return 0;
	if(v[s[(x-2+n)%n]]!=ooo)
		return 0;
}
int main()
{
	cin>>n;
	fr(i,2*n)
	{
		scanf("%d%d",&x,&y);
		a[x].push_back(y); 
		a[y].push_back(x);
	}
	fo(i,n)
	{
		if(a[i].size()!=4)
		{
			puts("-1");
			return 0;
		}
	}
	sort(a[1].begin(),a[1].end());
	int done=0;
	do
	{
		memset(v,0,sizeof v);
		memset(w,0,sizeof w);
		w[a[1][0]]=1;
		w[a[1][1]]=1;
		w[a[1][2]]=1;
		w[a[1][3]]=1;
		w[1]=1;
		done=1;
		s[n-1]=a[1][2];
		s[n]=s[0]=a[1][3];
		s[1]=1;
		s[2]=a[1][0];
		s[3]=a[1][1];
		if(s[n-1]==2&&s[n]==6)
			s[n]=6;
		for(int i=2;i+2<n-1;i++)
		{
			v[s[i-2]]=i;
			v[s[i-1]]=i;
			v[s[i+1]]=i;
			for(int j:a[s[i]])
				if(v[j]!=i&&!w[j])
				{
					s[i+2]=j;
					w[j]=1;
					goto can;
				}
			done=0;
			break;
			can:;
		}
		if(s[n-1]==2&&s[n]==6)
			s[n]=6;
		if(done&&ok(2)&&ok(3)&&ok(n-1)&&ok(n))
		{
			fo(i,n)
				printf("%d ",s[i]);
			puts("");
			return 0;
		}
	}
	while(next_permutation(a[1].begin(),a[1].end()));
	puts("-1");
	return 0;
}