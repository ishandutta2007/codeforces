#include <stdio.h>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
const int N=1050;
char word[N][5];
int main()
{
	int n,i,x;
	scanf("%s",&word[0]);
	scanf("%i",&n);
	bool ok=0,ok1=0,ok2=0;
	for(i=1;i<=n;i++)
	{
		scanf("%s",&word[i]);
		if(word[i][0]==word[0][0] && word[i][1]==word[0][1]) ok=true;
		if(word[i][1]==word[0][0]) ok1=true;
		if(word[i][0]==word[0][1]) ok2=true;
	}
	if(ok || (ok1 && ok2)) printf("YES\n");
	else printf("NO\n");
	return 0;
}