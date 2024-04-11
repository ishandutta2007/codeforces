#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
int x,y,ti,td,tr,te,la,lb,f[4020][4020],pa[4020][26],pb[4020][26];
char a[4020],b[4020];
int main()
{
	scanf("%d%d%d%d%s%s",&ti,&td,&tr,&te,a,b);
	la=strlen(a),lb=strlen(b);
	fo(i,la)
	{
		f[i][0]=i*td;
		memcpy(pa[i],pa[i-1],sizeof pa[0]);
		pa[i][a[i-1]-'a']=i;
	}
	fo(i,lb)
	{
		f[0][i]=i*ti;
		memcpy(pb[i],pb[i-1],sizeof pb[0]);
		pb[i][b[i-1]-'a']=i;
	}
	fr(i,la)
		fr(j,lb)
		{
			f[i+1][j+1]=min(min(f[i+1][j]+ti,f[i][j+1]+td),f[i][j]+(a[i]!=b[j]?tr:0));
			if((x=pa[i][b[j]-'a'])&&(y=pb[j][a[i]-'a']))
				f[i+1][j+1]=min(f[i+1][j+1],f[x-1][y-1]+te+(i-x)*td+(j-y)*ti);
		}
	printf("%d\n",f[la][lb]);
}