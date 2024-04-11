#include <stdio.h>
#include <vector>
using namespace std;
vector<bool> sol;
int main()
{
	int a1,h1,c,a2,h2;
	scanf("%i %i %i %i %i",&h1,&a1,&c,&h2,&a2);
	while(h2>0)
	{
		if(h2<=a1){ sol.push_back(0);break;}
		if(a2>=h1) sol.push_back(1),h1+=c;
		else sol.push_back(0),h2-=a1;
		h1-=a2;
	}
	printf("%i\n",sol.size());
	for(int i=0;i<sol.size();i++)
	{
		if(sol[i]) printf("HEAL\n");
		else printf("STRIKE\n");
	}
	return 0;
}