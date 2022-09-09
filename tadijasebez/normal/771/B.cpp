#include <stdio.h>
#include <vector>
using namespace std;
const int N=55;
vector<char> sol[N],tmp;
int p[N],c;
void init(){ for(int i=0;i<N;i++) p[i]=i;}
int Find(int x){ return p[x]==x?x:p[x]=Find(p[x]);}
void Union(int x, int y){ p[Find(x)]=Find(y);}
void DFS(int d)
{
	if(d>10 || c==N) return;
	sol[c++]=tmp;
	for(int i=0;i<26;i++)
	{
		tmp.push_back('a'+i);
		DFS(d+1);
		tmp.pop_back();
	}
}
int main()
{
	int n,i,j,k;char s[10];
	scanf("%i %i",&n,&k);
	init();
	for(i=1;i<=n-k+1;i++){ scanf("%s",s+1);if(s[1]=='N') Union(i,i+k-1);}
	DFS(0);
	for(i=1;i<=n;i++)
	{
		int x=Find(i);
		printf("%c",sol[x][0]-'a'+'A');
		for(j=1;j<sol[x].size();j++) printf("%c",sol[x][j]);
		printf(" ");
	}
	printf("\n");
	return 0;
}