#include<bits/stdc++.h>
using namespace std;
const int N=400005;
int a[N];
set<pair<int,int>>s;
int main()
{	
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
		s.insert(make_pair(0,i));
	while(n--)
	{
		int x;
		scanf("%d",&x);
		x%=m;
		s.erase(make_pair(a[x],x));
		a[x]++;
		s.insert(make_pair(a[x],x));
		int k=s.begin()->second;
		printf("%d\n",a[k]*m+k);
	}
	return 0;
}