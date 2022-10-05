#include <bits/stdc++.h>
using namespace std;
char a[8][7];
bool is[28];
int n;
int main()
{
	scanf("%d",&n);
	getchar(); 
	for(int i=1;i<=n;i++)
	{
		scanf("%s",a[i]);
		is[a[i][0]-'a']=true;
		getchar();
	}
	printf("%d\n",6-n);
	if(!is['p'-'a']) printf("Power\n");
	if(!is['g'-'a']) printf("Time\n");
	if(!is['b'-'a']) printf("Space\n");
	if(!is['o'-'a']) printf("Soul\n");
	if(!is['r'-'a']) printf("Reality\n");
	if(!is['y'-'a']) printf("Mind\n");
	return 0;
}