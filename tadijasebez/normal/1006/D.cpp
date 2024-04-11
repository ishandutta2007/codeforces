#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
const int N=100050;
char s[N],t[N];
vector<char> tmp;
int main()
{
	int n,i,j;
	scanf("%i",&n);
	scanf("%s",s+1);
	scanf("%s",t+1);
	int sol=0;
	for(i=1,j=n;i<=j;i++,j--)
	{
		//printf("%i %i\n",i,j);
		if(i==j){ if(s[i]!=t[i]) sol++;}
		else
		{
			tmp.clear();
			tmp.push_back(s[i]);
			tmp.push_back(s[j]);
			tmp.push_back(t[i]);
			tmp.push_back(t[j]);
			sort(tmp.begin(),tmp.end());
			int add=(int)(tmp[0]!=tmp[1])+(int)(tmp[2]!=tmp[3]);
			if(add==2 && tmp[1]==tmp[2]) add--;
			if(add==1 && s[i]==s[j] && tmp[0]!=tmp[2] && tmp[1]!=tmp[3]) add++;
			sol+=add;
			//printf("%c %c %c %c\n",tmp[0],tmp[1],tmp[2],tmp[3]);
		}
	}
	printf("%i\n",sol);
	return 0;
}