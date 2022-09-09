#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
const int N=55;
string s[N];
int m;
bool comp(int i, int x, int j, int y)
{
	return s[i].substr(x,m).compare(s[j].substr(y,m))==0;
}
int min(int a, int b){ return a>b?b:a;}
int main()
{
	int i,j,k,n;
	scanf("%i",&n);
	for(i=1;i<=n;i++) cin >> s[i],s[i]=s[i]+s[i];
	//for(i=1;i<=n;i++) cout << s[i] << "\n";
	m=s[1].size()/2;
	int sol=N*N;
	for(j=0;j<m;j++)
	{
		int ans=0;
		for(i=1;i<=n;i++)
		{
			for(k=0;k<m;k++)
			{
				if(comp(1,j,i,k))
				{
					ans+=k;
					break;
				}
			}
			if(k==m) return printf("-1"),0;
		}
		sol=min(sol,ans);
	}
	printf("%i\n",sol);
	return 0;
}