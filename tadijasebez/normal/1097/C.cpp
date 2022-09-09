#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ldb long double
template<typename T> bool ckmn(T &a, T b){ T c=a;a=min(a,b);return a!=c;}
template<typename T> bool ckmx(T &a, T b){ T c=a;a=max(a,b);return a!=c;}
const int N=500050;
char s[N];
int l[N],r[N];
int main()
{
	int n,i,j;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		int f=strlen(s+1);
		int a=0,b=0;
		for(j=1;j<=f;j++)
		{
			if(s[j]=='(') a++;
			else b++;
		}
		if(a>b)
		{
			bool ok=1;
			int b=0;
			for(j=1;j<=f;j++)
			{
				if(s[j]=='(') b++;
				else b--;
				if(b<0) ok=0;
			}
			if(ok) l[b]++;
			//printf("l:%i %i\n",i,b);
		}
		else
		{
			bool ok=1;
			int b=0;
			for(j=f;j>=1;j--)
			{
				if(s[j]==')') b++;
				else b--;
				if(b<0) ok=0;
			}
			if(ok) r[b]++;
			//printf("r:%i %i\n",i,b);
		}
	}
	int ans=0;
	for(i=1;i<N;i++) ans+=min(l[i],r[i]);
	ans+=r[0]/2;
	printf("%i\n",ans);
	return 0;
}