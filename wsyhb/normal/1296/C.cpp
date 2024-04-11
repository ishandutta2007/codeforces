#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,T=1e3+5;
char s[N];
int tot1,tot2;
void work(char x)
{
	if(x=='L') tot1++;
	if(x=='R') tot1--;
	if(x=='U') tot2++;
	if(x=='D') tot2--;
}
typedef pair<int,int> P;
map<P,int> M[T];
int main()
{
	int t;
	scanf("%d",&t);
	for(int j=1;j<=t;j++) 
	{
		int n;
		scanf("%d%s",&n,s+1);
		tot1=tot2=0;
		int ans=1e9,l=-1;
		M[j][P(0,0)]=1;
		for(int i=1;i<=n;i++)
		{
			work(s[i]);
			int x=M[j][P(tot1,tot2)];
			if(x&&i-x+1<ans)
			{
				ans=i-x+1;
				l=x;
			}
			M[j][P(tot1,tot2)]=i+1;
		}
		if(l==-1) printf("-1\n");
		else printf("%d %d\n",l,l+ans-1);
	}
	return 0;
}