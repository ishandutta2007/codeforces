#include<bits/stdc++.h>
using namespace std;
const int max_k=1e5+5;
int a[max_k];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m,k;
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=k;++i)
			scanf("%d",a+i);
		set<int> S;
		int cur=1;
		bool ans=true;
		for(int i=k;i>=1;--i)
		{
			while(!S.count(i))
			{
				if((int)S.size()==n*m-3)
				{
					ans=false;
					break;
				}
				assert(cur<=k);
				S.insert(a[cur++]);
			}
			if(!ans)
				break;
			S.erase(i);
		}
		puts(ans?"YA":"TIDAK");
	}
	return 0;
}