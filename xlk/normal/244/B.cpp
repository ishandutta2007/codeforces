#include<stdio.h>
#include<set>
using namespace std;
set<long long>s;
long long n;
void dfs(long long x,int y,int z)
{
	if(x>n)
		return;
	s.insert(x);
	if(10*x+y!=x)
		dfs(10*x+y,y,z);
	if(10*x+z!=x)
		dfs(10*x+z,y,z);
}
int main()
{
	scanf("%I64d",&n);
	for(int i=0;i<10;i++)
		for(int j=0;j<i;j++)
			dfs(0,i,j);
	printf("%d",s.size()-1);
	return 0;
}