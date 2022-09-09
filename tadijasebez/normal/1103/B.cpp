#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ldb long double
#define mt meke_tuple
template<typename T> bool ckmn(T &a, T b){ T c=a;a=min(a,b);return a!=c;}
template<typename T> bool ckmx(T &a, T b){ T c=a;a=max(a,b);return a!=c;}
char ch[5];
int ask(int x, int y)
{
	printf("? %i %i\n",x,y);
	fflush(stdout);
	scanf("%s",ch);
	if(ch[0]=='x') return 1;
	else return 0;
}
int main()
{
	for(;;)
	{
		char op[15];
		scanf("%s",op);
		if(op[0]!='s') return 0;
		int sz=1;
		int top=-1,bot=0,tmp=0;
		for(int i=1;i<=30;i++)
		{
			int a=1-ask(tmp,tmp+sz);
			if(a==0)
			{
				top=tmp+sz;
				bot=tmp;
				break;
			}
			tmp+=sz;
			sz*=2;
		}
		int ans=1;
		while(top>=bot)
		{
			int mid=top+bot>>1;
			if(!ask(mid,tmp)) top=mid-1,ans=mid;
			else bot=mid+1;
		}
		printf("! %i\n",ans);
		fflush(stdout);
	}
	return 0;
}