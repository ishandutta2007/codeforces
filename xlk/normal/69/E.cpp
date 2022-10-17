#include<stdio.h>
#include<map>
#include<set>
using namespace std;
set<int>s;
map<int,int>c;
void R(int x,int y)
{
	if(c[x]==1)
		s.erase(x);
	c[x]+=y;
	if(c[x]==1)
		s.insert(x);	
}
void G()
{
	if(s.size())
		printf("%d\n",*s.rbegin());
	else
		puts("Nothing");
}
int n,k,a[100020];
int main()
{
	scanf("%d %d",&n,&k);
	for(int i=1;i<k;i++)
		scanf("%d",a+i),R(a[i],1);
	for(int i=k;i<=n;i++)
		scanf("%d",a+i),R(a[i],1),G(),R(a[i-k+1],-1);
	return 0;
}