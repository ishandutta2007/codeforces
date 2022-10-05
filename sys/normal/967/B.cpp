#include <bits/stdc++.h>
using namespace std;
int alll,A,B,n,ss[100005];
struct hol
{
	int s,id;
	bool operator < (const hol &a)const
	{
		return s>a.s;
	}
}hole[100005];
int main()
{
	scanf("%d%d%d",&n,&A,&B);
	for(int i=1;i<=n;i++)
	{
		hole[i].id=i;
		scanf("%d",&hole[i].s);
		ss[i]=hole[i].s;
		alll+=ss[i];
	}
	int cnt=0,ddd=A*ss[1];
	sort(hole+1,hole+1+n);
	for(int i=1;i<=n;i++)
	{
		if(ddd/(double)alll>=B){printf("%d",cnt);return 0;}
		if(hole[i].id!=1)
		{
			cnt++;
			alll-=hole[i].s;
		}		
	}
	if(ddd/(double)alll>=B){printf("%d",cnt);}
	return 0;
}