#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ldb long double
#define mt meke_tuple
template<typename T> bool ckmn(T &a, T b){ T c=a;a=min(a,b);return a!=c;}
template<typename T> bool ckmx(T &a, T b){ T c=a;a=max(a,b);return a!=c;}
const int N=10050;
char T[N],S[N],t[3][N],s[3][N];
int main()
{
	scanf("%s",T);
	int n=strlen(T),i;
	for(i=0;i<n;i++) s[0][i]='a'+(i%26);
	for(i=0;i<n;i++) s[1][i]='a'+((i/26)%26);
	for(i=0;i<n;i++) s[2][i]='a'+((i/(26*26))%26);
	for(i=0;i<3;i++)
	{
		printf("? %s\n",s[i]);
		fflush(stdout);
		scanf("%s",t[i]);
	}
	for(i=0;i<n;i++)
	{
        int id=(t[2][i]-'a')*26*26+(t[1][i]-'a')*26+(t[0][i]-'a');
        S[id]=T[i];
	}
	printf("! %s\n",S);
	fflush(stdout);
	return 0;
}