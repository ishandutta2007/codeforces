#include <stdio.h>
#include <cstring>
#include <vector>
using namespace std;
vector< vector<char> > cur;
char word[500],t[10];
void Print()
{
	int i,j;
	for(i=0;i<cur.size();i++){
		printf("/");
		for(j=0;j<cur[i].size();j++) printf("%c",cur[i][j]);
	}
	printf("/\n");
}
vector<char> Get(int &x, int n)
{
	vector<char> tmp;
	for(;x<n && word[x]!='/';x++) tmp.push_back(word[x]);
	x++;
	return tmp;
}
int main()
{
	int q,n;
	scanf("%i",&q);
	while(q --> 0)
	{
		scanf("%s",&t);
		if(t[0]=='c')
		{
			scanf("%s",&word);
			n=(unsigned) strlen(word);
			int x=0;
			if(word[0]=='/') cur.clear(),x++;
			vector<char> tmp;tmp=Get(x,n);
			while(!tmp.empty())
			{
				if(tmp.size()==2 && tmp[0]=='.' && tmp[1]=='.') cur.pop_back();
				else cur.push_back(tmp);
				tmp=Get(x,n);
			}
		}
		else Print();
		//printf("%i\n",q);
	}
	return 0;
}