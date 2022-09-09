#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> sol,input;
int max(int a, int b){ return a>b?a:b;}
int max(int a, int b, int c){ return max(a,max(b,c));}
int main()
{
	int i,v,x;
	for(i=0;i<3;i++) scanf("%i",&x),input.push_back(x);
	scanf("%i",&v);
	sol.push_back(max(v,input[2]));
	sol.push_back(max(v*2+1,input[1],sol[0]+1));
	sol.push_back(max(v*2+1,input[0],sol[1]+1));
	reverse(sol.begin(),sol.end());
	if(sol[2]>v*2) return printf("-1\n"),0;
	for(i=0;i<3;i++) if(sol[i]>2*input[i]) return printf("-1\n"),0;
	for(i=0;i<3;i++) printf("%i\n",sol[i]);
	return 0;
}