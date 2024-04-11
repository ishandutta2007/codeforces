#include <stdio.h>
#include <stack>
#include <cstring>
using namespace std;
stack<char> s;
int sol;
bool possible=true;
char word[1000500];
int main()
{
	int n,i;
	scanf("%s",&word);
	n=(unsigned) strlen(word);
	for(i=0;i<n;i++)
	{
		if(word[i]=='(' || word[i]=='<' || word[i]=='[' || word[i]=='{') s.push(word[i]);
		else
		{
			if(s.empty()){ possible=false;break;}
			if(word[i]==')') if(s.top()!='(') sol++;
			if(word[i]=='}') if(s.top()!='{') sol++;
			if(word[i]==']') if(s.top()!='[') sol++;
			if(word[i]=='>') if(s.top()!='<') sol++;
			s.pop();
		}
	}
	if(!s.empty()) possible=false;
	if(!possible) printf("Impossible\n");
	else printf("%i\n",sol);
	return 0;
}