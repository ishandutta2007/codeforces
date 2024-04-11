#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=1000050;
char s[N];
int main()
{
	int n,i;
	scanf("%s",s+1);
	n=strlen(s+1);
	int b=0;
	for(i=1;i<=n;i++) b+=s[i]!='a';
	if(b&1) return 0*printf(":(\n");
	int len=n-b/2;
	int j=1;
	for(i=len+1;i<=n;i++)
	{
		while(s[j]=='a') j++;
		if(j>len || s[j]!=s[i] || s[i]=='a') return 0*printf(":(\n");
		j++;
	}
	for(i=1;i<=len;i++) printf("%c",s[i]);
	return 0;
}