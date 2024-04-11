#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define pb push_back
const int N=205;
vector<char> sol;
bool was[N][N][N];
void Recur(int r, int g, int b)
{
	if(was[r][g][b]) return;
	was[r][g][b]=1;
	if(!r && !g) sol.pb('B');
	else if(!r && !b) sol.pb('G');
	else if(!b && !g) sol.pb('R');
	else
	{
		if(r && g) Recur(r-1,g-1,b+1);
		if(r && b) Recur(r-1,g+1,b-1);
		if(b && g) Recur(r+1,g-1,b-1);
		if(r>1) Recur(r-1,g,b);
		if(g>1) Recur(r,g-1,b);
		if(b>1) Recur(r,g,b-1);
	}
}
char s[N];
int main()
{
	int n,i,r=0,g=0,b=0;
	scanf("%i",&n);
	scanf("%s",s+1);
	for(i=1;i<=n;i++)
	{
		r+=s[i]=='R';
		g+=s[i]=='G';
		b+=s[i]=='B';
	}
	Recur(r,g,b);
	sort(sol.begin(),sol.end());
	sol.erase(unique(sol.begin(),sol.end()),sol.end());
	for(i=0;i<sol.size();i++) printf("%c",sol[i]);
	printf("\n");
	return 0;
}