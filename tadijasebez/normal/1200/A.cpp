#include <bits/stdc++.h>
using namespace std;
const int N=100050;
int a[10];
char s[N];
int main()
{
	int n;
	scanf("%i",&n);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
	{
		switch(s[i])
		{
			case 'L':
				for(int j=0;j<10;j++) if(!a[j]){ a[j]=1;break;}
				break;
			case 'R':
				for(int j=9;j>=0;j--) if(!a[j]){ a[j]=1;break;}
				break;
			default:
				a[s[i]-'0']=0;
				break;
		}
	}
	for(int i=0;i<10;i++) printf("%i",a[i]);
	return 0;
}