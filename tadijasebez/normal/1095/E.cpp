#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=1000050;
char s[N];
bool lok[N],rok[N];
int lsz[N],rsz[N];
int main()
{
	int n,i;
	scanf("%i",&n);
	scanf("%s",s+1);
	int b=0;lok[0]=1;
	for(i=1;i<=n;i++)
	{
		if(s[i]=='(') b++;
		else b--;
		if(b<0) lok[i]=0;
		else lok[i]=lok[i-1];
		lsz[i]=b;
	}
	b=0;rok[n+1]=1;
	for(i=n;i>=1;i--)
	{
		if(s[i]==')') b++;
		else b--;
		if(b<0) rok[i]=0;
		else rok[i]=rok[i+1];
		rsz[i]=b;
	}
	int ans=0;
	for(i=1;i<=n;i++)
	{
		if(lok[i-1] && rok[i+1])
		{
			b=lsz[i-1]-rsz[i+1];
			if(s[i]=='(' && b==1) ans++;
			else if(s[i]==')' && b==-1) ans++;
		}
	}
	printf("%i\n",ans);
	return 0;
}