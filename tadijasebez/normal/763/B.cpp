#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,i,x1,y1,x2,y2;
	scanf("%i",&n);
	vector<int> ans;
	for(int i=1;i<=n;i++)
	{
		scanf("%i %i %i %i",&x1,&y1,&x2,&y2);
		ans.push_back((abs(x1)%2)+(abs(y1)%2)*2+1);
	}
	printf("YES\n");
	for(int j:ans) printf("%i\n",j);
	return 0;
}