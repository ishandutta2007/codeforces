#include <bits/stdc++.h>
using namespace std;
int T;
string s,t;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		cin>>s>>t;
		s+='#';
		int n=s.size(),m=t.size();
		int pnt=0,cnt=0;
		for(int i=0;i<n;i++)
		{
			if(s[i]!=s[i-1])
			{
				int tmp=0;
				while(pnt<m&&t[pnt]==s[i-1]) tmp++,pnt++;
				if(tmp<cnt)
				{
					printf("NO\n");
					goto A;
				}
				cnt=1;
			}
			else cnt++;
		}
		if(pnt==m)
			printf("YES\n");
		else printf("NO\n");
		A:;
	}
	return 0;
}