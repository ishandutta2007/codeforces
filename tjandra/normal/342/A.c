#include<stdio.h>
typedef unsigned u;
u n[8],d[8];
int main()
{
	u t,i,k,stn=0,sdp=0,sdn=0,tot=0;
	for(i=0,scanf("%u",&t);i<t;i++)
	{
		scanf("%u",&k);n[k]++;
	}
	i=n[3];if(i>n[6])i=n[6];
	if(n[1]<i)i=n[1];
	stn=i;
	n[1]-=i;
	i=n[2];
	if(i>n[4])i=n[4];
	if(n[1]<i)i=n[1];
	sdp=i;
	n[1]-=i;n[2]-=i;
	i=n[2];
	if(i>n[6])i=n[6];
	if(n[1]<i)i=n[1];
	sdn=i;
	tot=stn+sdp+sdn;
	if(tot<t/3){printf("-1\n");return 0;}
	tot=t/3;
	while(tot--)
	{
		if(sdp){sdp--;printf("1 2 4\n");continue;}
		if(sdn){sdn--;printf("1 2 6\n");continue;}
		if(stn){stn--;printf("1 3 6\n");continue;}
	}
	return 0;
}