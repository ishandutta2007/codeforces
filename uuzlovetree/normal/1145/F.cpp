#include<bits/stdc++.h>
using namespace std;
#define maxn 15
char s[maxn];
bool has1[500],has2[500];
int main()
{
	scanf("%s",s);
	int n=strlen(s);
	int ans=0;
	has1['A']=1;
	has2['B']=1;
	has2['C']=1;
	has2['D']=1;
	has1['E']=1;
	has1['F']=1;
	has2['G']=1;
	has1['H']=1;
	has1['I']=1;
	has2['J']=1;
	has1['K']=1;
	has1['L']=1;
	has1['M']=1;
	has1['N']=1;
	has2['O']=1;
	has2['P']=1;
	has2['Q']=1;
	has2['R']=1;
	has2['S']=1;
	has1['T']=1;
	has2['U']=1;
	has1['V']=1;
	has1['W']=1;
	has1['X']=1;
	has1['Y']=1;
	has1['Z']=1;
	bool f1=0,f2=0;
	for(int i=0;i<n;++i)
	{
		f1|=has1[s[i]];
		f2|=has2[s[i]];
	}
	if(f1&&f2)puts("NO");
	else puts("YES");
}