#include <bits/stdc++.h>
using namespace std;
int n,l,r,cnt; 
string str,res;
int main()
{
	cin>>str;
	while(str!="end")
	{
		cnt=0;
		for(long long i=1;;i<<=1)
		{
			printf("? %lld %lld\n",i,min(2000000000LL,i*2)),cnt++;
			fflush(stdout);
			cin>>res;
			if(res=="x")
			{
				l=i,r=(int)min(1000000000LL,i*2);
				break;
			}
		}
		while(l+1<=r)
		{
			int mid=(l+r)/2;
			printf("? %d %d\n",2*mid,mid),cnt++;
			fflush(stdout);
			cin>>res;
			if(res=="x")
				r=mid;
			else l=mid+1;
		}
		if(l==2)
		{
			printf("? 2 1\n");
			fflush(stdout);
			cin>>res;
			if(res=="x")
			{
				printf("! 1\n");
				fflush(stdout);
				goto A;
			}
			else
			{
				printf("! 2\n");
				fflush(stdout);
				goto A;
			}
		}
		if(cnt>60) 1/0;
		printf("! %d\n",l);
		fflush(stdout);
		A:cin>>str;
		if(str=="mistake")
			1/0;
	}
	return 0;
}