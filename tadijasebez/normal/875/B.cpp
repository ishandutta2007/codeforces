#include <stdio.h>
#include <vector>
using namespace std;
vector<int> v;
const int N=300050;
int a[N];
int main()
{
	int n,j,i,x;
	scanf("%i",&n);
	j=n+1;
	v.push_back(1);
	for(i=1;i<=n;i++)
	{
		scanf("%i",&x);
		a[x]=1;
		while(j && a[j-1]==1) j--;
		v.push_back(i-(n+1-j)+1);
	}
	for(i=0;i<v.size();i++) printf("%i ",v[i]);
	return 0;
}