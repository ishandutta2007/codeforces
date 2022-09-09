#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define pb push_back
char s[5];
vector<char> a,b,c;
int main()
{
	int i,j;
	scanf("%s",s+1);
	if(s[1]!='X') a.pb(s[1]);
	if(s[2]!='X') a.pb(s[2]);
	scanf("%s",s+1);
	if(s[2]!='X') a.pb(s[2]);
	if(s[1]!='X') a.pb(s[1]);
	scanf("%s",s+1);
	if(s[1]!='X') b.pb(s[1]);
	if(s[2]!='X') b.pb(s[2]);
	scanf("%s",s+1);
	if(s[2]!='X') b.pb(s[2]);
	if(s[1]!='X') b.pb(s[1]);
	for(i=0;i<3;i++)
	{
		if(a[i]==b[0])
		{
			c.pb(a[i]);
			for(j=i+1;j<3;j++) c.pb(a[j]);
			for(j=0;j<i;j++) c.pb(a[j]);
			break;
		}
	}
	//for(i=0;i<3;i++) printf("%c",a[i]);printf("\n");
	//for(i=0;i<3;i++) printf("%c",b[i]);printf("\n");
	//for(i=0;i<3;i++) printf("%c",c[i]);printf("\n");
	if(c==b) printf("YES\n");
	else printf("NO\n");
	return 0;
}