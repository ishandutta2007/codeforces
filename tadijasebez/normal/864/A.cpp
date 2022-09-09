#include <stdio.h>
#include <vector>
using namespace std;
const int N=150;
int count[N];
vector<int> num;
int main()
{
	int n,x,i;
	scanf("%i",&n);
	for(i=0;i<n;i++)
	{
		scanf("%i",&x);
		if(!count[x]) num.push_back(x);
		count[x]++;
	}
	if(num.size()==2)
	{
		if(count[num[0]]==count[num[1]])
		{
			printf("YES\n");
			printf("%i %i\n",num[0],num[1]);
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}