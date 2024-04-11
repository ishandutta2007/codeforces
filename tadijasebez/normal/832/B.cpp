#include <stdio.h>
#include <cstring>
bool good[26];
char word[100050];
char query[100050];
int main()
{
	int n,m,i,j,q,k;
	scanf("%s",&word);
	k=(unsigned) strlen(word);
	for(i=0;i<k;i++) good[word[i]-'a']=true;
	scanf("%s",&word);
	n=(unsigned) strlen(word);
	scanf("%i",&q);
	while(q--)
	{
		scanf("%s",&query);
		m=(unsigned) strlen(query);
		bool ok=true;
		j=0;
		if(m<n-1) ok=false;
		for(i=0;i<m;i++)
		{
			if(word[j]=='?')
			{
				if(!good[query[i]-'a']) ok=false;
				j++;
			}
			else if(word[j]=='*')
			{
				if(m<n) j++,i--;
				else 
				{
					if(good[query[i]-'a']) ok=false;
					if(n-j==m-i) j++;
				}
			}
			else
			{
				if(word[j]!=query[i]) ok=false;
				j++;
			}
		}
		if(j!=n)
		{
			if(j!=n-1) ok=false;
			if(j==n-1 && word[n-1]!='*') ok=false;
		}
		if(ok) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}