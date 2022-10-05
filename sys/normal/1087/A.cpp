#include <bits/stdc++.h>
using namespace std;
string str;
char ch[1000005];
int main()
{
	cin>>str;
	int siz=str.size();
	int i,rt=siz-1,lt=0,cnt=0;
	if(siz%2) i=0;
	else i=1;
	for(;i<=siz;i++)
	{
		if(i%2==0)
			ch[++cnt]=str[lt],lt++;
		if(i%2) ch[++cnt]=str[rt],rt--;
	}
	for(int i=siz;i>=1;i--)
		printf("%c",ch[i]);
	return 0;
}