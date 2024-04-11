#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
char ch[12000];
int S(int x)
{
	if(ch[x]>='a'&&ch[x]<='z')return 0;
	if(ch[x]>='A'&&ch[x]<='Z')return 0;
	if(ch[x]=='.')return 1;
	if(ch[x]=='?')return 1;
	if(ch[x]=='!')return 1;
	return 2;
}
int i,ans,wn,use;
int main()
{
	while(~scanf("%d",&n))
	{
		gets(ch);
		gets(ch);
		int le=strlen(ch);
		ans=1;bool can=true;
		use=0;int st=0;int kg=0;
		for(i=0;i<le;i++)
		{
		//	printf("%d %d %d %d\n",i,ans,use,wn);
			if(st==1)
			{
				while(ch[i]==' '){i++;kg++;}
			}
			if(S(i)==0||S(i)==2)
			{
				wn++;st=0;
			}
			if(S(i)==1)
			{
				wn++;
				if(wn>n){can=false;break;}
				if(wn+use+kg>n)
				{
					use=wn;ans++;
				}
				else
				{
					use+=wn;
					use+=kg;
				}
				wn=0;st=1;kg=0;
			}
		}
		if(can)printf("%d\n",ans);
		else puts("Impossible");
	}
}