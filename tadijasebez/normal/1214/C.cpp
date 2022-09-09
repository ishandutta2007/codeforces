#include <bits/stdc++.h>
using namespace std;
const int N=200050;
char s[N];
int main()
{
	int n;
	scanf("%i",&n);
	scanf("%s",s+1);
	bool fir=1;
	int b=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='(') b++;
		else
		{
			if(fir) fir=0;
			else b--;
		}
		if(b<0) return 0*printf("No\n");
	}
	if(!fir) b--;
	if(b==0) printf("Yes\n");
	else printf("No\n");
	return 0;
}