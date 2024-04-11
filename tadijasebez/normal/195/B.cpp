#include <stdio.h>
#include <algorithm>
using namespace std;
int n,m;
bool comp(int i, int j)
{
	if(abs((double)(m+1)/2-i)<abs((double)(m+1)/2-j)) return true;
	if(abs((double)(m+1)/2-i)>abs((double)(m+1)/2-j)) return false;
	return i<j;
}
const int N=100050;
int a[N];
int main()
{
	int i;
	scanf("%i %i",&n,&m);
	for(i=1;i<=m;i++) a[i]=i;
	sort(a+1,a+1+m,comp);
	for(i=1;i<=n;i++){
		int tmp=i%m;
		if(!tmp) tmp=m;
		printf("%i\n",a[tmp]);
	}
	return 0;
}