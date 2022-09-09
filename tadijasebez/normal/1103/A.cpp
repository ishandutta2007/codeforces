#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ldb long double
#define mt meke_tuple
template<typename T> bool ckmn(T &a, T b){ T c=a;a=min(a,b);return a!=c;}
template<typename T> bool ckmx(T &a, T b){ T c=a;a=max(a,b);return a!=c;}
const int N=100050;
char s[N];
int main()
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	bool has1=0,has0=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='1')
		{
			if(has1)
			{
				printf("4 1\n");
				has1=0;
			}
			else
			{
				printf("4 3\n");
				has1=1;
			}
		}
		else
		{
			if(has0)
			{
				printf("3 1\n");
				has0=0;
			}
			else
			{
				printf("1 1\n");
				has0=1;
			}
		}
	}
	return 0;
}