#include <stdio.h>
#include <stack>
using namespace std;
const int N=200050;
int c=1,a[N];
bool in[N];
stack<int> s,tmp;
int main()
{
	int n,k,i,x;
	scanf("%i %i",&n,&k);
	for(i=1;i<=k;i++)
	{
		scanf("%i",&a[i]);
		if(a[i]==c)
		{
			c++;
		}
		else
		{
			s.push(a[i]);
			in[a[i]]=1;
		}
		while(!s.empty() && s.top()==c) in[s.top()]=0,s.pop(),c++;
	}
	while(!s.empty())
	{
		if(s.top()==c)
		{
			in[s.top()]=0;
			//a[++k]=s.top();
			while(!tmp.empty()) a[++k]=tmp.top(),tmp.pop();
			c++;
			s.pop();
		}
		else
		{
			if(in[c]) return printf("-1\n"),0;
			//a[++k]=c;
			tmp.push(c);
			c++;
		}
	}
	while(c<=n) tmp.push(c),c++;
	while(k<n) a[++k]=tmp.top(),tmp.pop();
	for(i=1;i<=n;i++) printf("%i ",a[i]);
	return 0;
}