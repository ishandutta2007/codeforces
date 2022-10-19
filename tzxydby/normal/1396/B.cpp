#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,a[N];
set<pair<int,int>>s;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		s.clear();
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			s.insert(make_pair(-a[i],i));
		}
		int l=0,zh=0;
		while(1)
		{
			if(s.size()==1)
			{
				puts(zh?"HL":"T");
				break;
			}
			int x=s.begin()->second;
			s.erase(s.begin());
			if(x!=l)
			{
				a[x]--;
				if(a[x]) s.insert(make_pair(-a[x],x));
				l=x;
			}	
			else
			{
				int y=s.begin()->second;
				s.erase(s.begin());
				a[y]--;
				if(a[x]) s.insert(make_pair(-a[x],x));
				if(a[y]) s.insert(make_pair(-a[y],y));
				l=y;
			}
			zh^=1;
		}
	}
	return 0;
}