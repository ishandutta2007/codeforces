#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int a,b,c,d,n;
int Ans[maxn];
int main()
{
	cin>>a>>b>>c>>d;
	n=a+b+c+d;
	if(abs(a+c-b-d)>1)
	{
		puts("NO");
		exit(0);
	}
	if(a+c>=b+d)
	{
		memset(Ans,-1,sizeof(Ans));
		for(int i=1;i<=a;++i)Ans[i*2-1]=0;
		for(int i=a+1;i<=a+c;++i)Ans[i*2-1]=2;
		for(int i=1;i<=b;++i)Ans[i*2]=1;
		for(int i=b+1;i<=b+d;++i)Ans[i*2]=3;
		bool yes=1; 
		for(int i=1;i<n;++i)if(abs(Ans[i]-Ans[i+1])>1)yes=0;
		if(yes)
		{
			puts("YES");
			for(int i=1;i<=n;++i)printf("%d ",Ans[i]);
			exit(0);
		}
	}
	if(a+c<=b+d)
	{
		memset(Ans,-1,sizeof(Ans));
		for(int i=1;i<=b;++i)Ans[i*2-1]=1;
		for(int i=b+1;i<=b+d;++i)Ans[i*2-1]=3;
		for(int i=1;i<=a;++i)Ans[i*2]=0;
		for(int i=a+1;i<=a+c;++i)Ans[i*2]=2;
		bool yes=1; 
		for(int i=1;i<n;++i)if(abs(Ans[i]-Ans[i+1])>1)yes=0;
		if(yes)
		{
			puts("YES");
			for(int i=1;i<=n;++i)printf("%d ",Ans[i]);
			exit(0);
		}
	}
	puts("NO");
}