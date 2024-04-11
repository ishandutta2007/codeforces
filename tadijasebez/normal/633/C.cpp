#include <stdio.h>
#include <vector>
#include <string>
#include <stack>
using namespace std;
vector<char> ReadString()
{
	vector<char> ret;
	char c=getchar();
	while(!(c>='A' && c<='Z') && !(c>='a' && c<='z')) c=getchar();
	while((c>='A' && c<='Z') || (c>='a' && c<='z')) ret.push_back(c),c=getchar();
	return ret;
}
vector<char> Build(vector<char> v)
{
	vector<char> ret;
	for(int i=0;i<v.size();i++) ret.push_back(tolower(v[i]));
	return ret;
}
void PrintString(vector<char> v)
{
	for(int i=0;i<v.size();i++) printf("%c",v[i]);
	printf(" ");
}
const int N=100050;
const int M=1000500;
vector<char> Word[N],tmp,ch;
int go[M][26],out[M],clock,root,p[N];
void Set(int lvl, int sz, int j, int &c)
{
	if(!c) c=++clock;
	if(lvl==sz){ out[c]=j;return;}
	Set(lvl+1,sz,j,go[c][tmp[lvl]-'a']);
}
int cur;
int Move(char c)
{
	cur=go[cur][c-'a'];
	return out[cur];
}
stack< vector<char> > sol;
int main()
{
	int n,m,i,j,g;
	scanf("%i",&n);
	ch=ReadString();
	scanf("%i",&m);
	for(i=1;i<=m;i++)
	{
		Word[i]=ReadString();
		tmp=Build(Word[i]);
		Set(0,tmp.size(),i,root);
	}
	p[0]=m+1;
	for(i=1;i<=n;i++)
	{
		j=i;cur=root;
		while(j && i-j+1<=1050)
		{
			j--;g=Move(ch[j]);
			if(g && p[j]) p[i]=g;
		}
	}
	i=n;
	while(i)
	{
		sol.push(Word[p[i]]);
		i-=Word[p[i]].size();
	}
	while(!sol.empty()) PrintString(sol.top()),sol.pop();
	return 0;
}