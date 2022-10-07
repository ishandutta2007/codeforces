#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,k,l1,r1,l2,r2;
char s[100005];
int main()
{
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	l1=1;
	while(s[l1]=='1')l1++;
	l2=1;
	while(s[l2]=='0')l2++;
	r1=n;
	while(s[r1]=='1')r1--;
	r2=n;
	while(s[r2]=='0')r2--;
	if(r1-l1+1<=k||r2-l2+1<=k)return puts("tokitsukaze"),0;
	if(r1-l1+1>=k+2||r2-l2+1>=k+2)return puts("once again"),0;
	if(n==2*k+2)puts("once again");
	else puts("quailty");
	return 0;
}