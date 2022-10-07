#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char s[15][15];
int t;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
	for(int i=1;i<=9;i++)scanf("%s",s[i]+1);
	s[1][1]=s[1][2];
	s[2][4]=s[2][5];
	s[3][7]=s[3][8];
	
	s[4][2]=s[4][3];
	s[5][5]=s[5][6];
	s[6][8]=s[6][9];
	
	s[7][3]=s[7][1];
	s[8][6]=s[8][4];
	s[9][9]=s[9][7];
	for(int i=1;i<=9;i++)printf("%s\n",s[i]+1);
	}
	return 0;
}