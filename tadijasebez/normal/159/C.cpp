#include <stdio.h>
#include <cstring>
char Base[105];
bool Del[2050][105];
int C[2050][26];
int n,m;
void Prepare()
{
	int i,j;
	for(j=0;j<m;j++) C[0][Base[j]-'a']++;
	for(i=1;i<=n;i++)
	{
		for(j=0;j<26;j++) C[i][j]=C[0][j];
	}
}
void Find(int p, char x)
{
	int s=0,j=0,i;
	while(s<p) j++,s+=C[j][x-'a'];
	s-=C[j][x-'a'];
	for(i=0;i<m;i++)
	{
		if(!Del[j][i] && Base[i]==x) s++;
		if(s==p)
		{
			Del[j][i]=1;
			break;
		}
	}
	C[j][x-'a']--;
}
void Print()
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(!Del[i][j]) printf("%c",Base[j]);
		}
	}
	printf("\n");
}
int main()
{
	scanf("%i",&n);
	scanf("%s",&Base);
	m=strlen(Base);
	Prepare();
	int q,i,p;
	char x;
	scanf("%i",&q);
	while(q--) scanf("%i %c",&p,&x),Find(p,x);
	Print();
	return 0;
}