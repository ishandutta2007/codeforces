#include <stdio.h>
#include <cstring>
const int N=100050;
int Trie[N][26],clock,root;
bool win[N],lose[N];
char word[N];
void Set(int &c, int pos, int len)
{
	if(!c) c=++clock;
	if(pos==len) return;
	Set(Trie[c][word[pos]-'a'],pos+1,len);
}
void DFS(int c)
{
	int i,j=0;
	for(i=0;i<26;i++)
	{
		if(Trie[c][i])
		{
			j++;
			DFS(Trie[c][i]);
			win[c]=win[c] || !win[Trie[c][i]];
			lose[c]=lose[c] || !lose[Trie[c][i]];
		}
	}
	if(!j) lose[c]=true;
}
int main()
{
	int n,k,i,t;
	scanf("%i %i",&n,&k);
	for(i=0;i<n;i++)
	{
		scanf("%s",&word);
		t=(unsigned) strlen(word);
		Set(root,0,t);
	}
	DFS(root);
	if(!win[root]) printf("Second\n");
	else if(win[root] && lose[root]) printf("First\n");
	else if(k%2==0) printf("Second\n");
	else printf("First\n");
	return 0;
}