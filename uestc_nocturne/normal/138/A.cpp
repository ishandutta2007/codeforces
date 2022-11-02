/*
Author: elfness@UESTC
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long LL;
bool can[10];//aaaa aabb abab abba
bool co[12][12];
char s[6][120000];
int n,K,i,j,k,l,nu[120];
int main()
{
	while(~scanf("%d%d",&n,&K))
	{
		for(i=0;i<4;i++)can[i]=true;
		for(i=0;i<n;i++)
		{
			for(j=0;j<4;j++)
			{
				scanf("%s",s[j]);
				nu[j]=strlen(s[j]);
			}
			for(j=0;j<4;j++)
			for(k=j+1;k<4;k++)
			{
				bool C=true;
				int te=0;
				for(l=0;;l++)
				{
					if(te==K)break;
					if(nu[j]<=l||nu[k]<=l)
					{C=false;break;}
					if(s[j][nu[j]-1-l]!=s[k][nu[k]-1-l])
					{C=false;break;}
					char tt=s[j][nu[j]-1-l];
					if(tt=='a'||tt=='e'||tt=='i'||tt=='o'||tt=='u')
					te++;
				}
			//	if(C)printf("%d %d\n",j,k);
				if(C)co[j][k]=true;
				else {co[j][k]=false;can[0]=false;}
			}
			if(!co[0][1]||!co[2][3])can[1]=false;
			if(!co[0][2]||!co[1][3])can[2]=false;
			if(!co[0][3]||!co[1][2])can[3]=false;
		}
		if(can[0])puts("aaaa");
		else if(can[1])puts("aabb");
		else if(can[2])puts("abab");
		else if(can[3])puts("abba");
		else puts("NO");
	}
}