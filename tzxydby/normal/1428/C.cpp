#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int t,n,a[N],r,x;
char s[N];
vector<int>v;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		r=n,x=0;
		v.clear();
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='A')
			{
				a[i]=1;
				v.push_back(1);
			}
			else
			{
				a[i]=2;
				if(v.size()&&v.back()==1)
				{
					v.pop_back();
					r-=2;
				}
				else
					v.push_back(2);
			}
		}
		for(auto i:v)
			if(i==2)
				x++;
		r-=x/2*2;
		printf("%d\n",r);
	}
	return 0;
}