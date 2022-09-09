#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=100050;
int lvl;
ll S[N],P[N];
int main()
{
	int n,x;
	scanf("%i",&n);
	for(int i=1;i<=n;i++)
	{
		char s[5];
		scanf("%s",s);
		if(s[0]=='a') P[lvl]++;
		else if(s[0]=='e') P[lvl-1]+=P[lvl]*S[lvl],lvl--;
		else scanf("%i",&x),S[++lvl]=x,P[lvl]=0;
		if(P[lvl]>>32) return 0*printf("OVERFLOW!!!\n");
	}
	printf("%lld\n",P[0]);
	return 0;
}