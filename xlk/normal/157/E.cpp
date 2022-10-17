#include<vector>
#include<algorithm>
#include<utility>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<time.h>
#include<bitset>
#include<map>
#include<queue>
#include<stack>
#include<set>
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define rf(i,n) for(int i=n-1;i>=0;i--)
#define of(i,n) for(int i=n;i>0;i--)
#define scan(x) scanf("%d",&x);
#define scans(x) scanf("%s",&x);
#define scand(x) scanf("%lf",&x);
#define print(x) printf("%d ",x);

const int inf=0x3fffffff;
using namespace std;
char c[200];
int f[105][2620];
int s[105][2620];
int l;
int cnt,tt;
int p=1000000007;
int main()
{
	f[0][0]=1;
	fo(i,2600)
		s[0][i]=1;
	fo(i,100)
	{
		for(int j=1;j<=2600;j++)
		{
			f[i][j]=s[i-1][j]-s[i-1][j-min(j,26)];
			if(f[i][j]>=p)
				f[i][j]-=p;				
			if(f[i][j]<0)
				f[i][j]+=p;				
			s[i][j+1]=s[i][j]+f[i][j];
			if(s[i][j+1]>=p)
				s[i][j+1]-=p;
		}
	}
	scan(tt);
	while(tt--)
	{
		scanf("%s",c);
		memset(s,0,sizeof(s));
		cnt=0;
		l=strlen(c);
		fr(i,l)
			cnt+=c[i]-'a'+1;
		printf("%d\n",f[l][cnt]-1);
	}
	return 0;
}