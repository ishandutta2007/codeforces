#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
#define PB push_back

vector<char> V;
char C[100001];

int main()
{
	int i=0;
	scanf("%s", C);
	while((int)C[i]!=0)
	{
		if(V.empty() || V[V.size()-1]!=C[i]) V.PB(C[i]);
		else V.pop_back();
		i++;
	}
	if(!V.empty()) printf("NO\n");
	else printf("YES\n");
	return 0;
}