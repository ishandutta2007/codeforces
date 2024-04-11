#include <bits/stdc++.h>
using namespace std;
int main()
{
	set<pair<int,int> > st;
	int n,i,k,q;
	scanf("%i %i %i",&n,&k,&q);
	vector<int> t(n);
	for(int &i:t) scanf("%i",&i);
	while(q--)
	{
		int ty,x;
		scanf("%i %i",&ty,&x);
		x--;
		if(ty==1)
		{
			st.insert({t[x],x});
			if(st.size()>k) st.erase(st.begin());
		}
		else
		{
			bool ok=0;
			for(auto p:st) if(p.second==x) ok=1;
			printf("%s\n",ok?"YES":"NO");
		}
	}
	return 0;
}