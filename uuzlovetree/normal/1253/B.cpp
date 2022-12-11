#include<bits/stdc++.h>
using namespace std;
int n;
set<int> s,used;
int main()
{
	scanf("%d",&n);
	bool yes=1;
	vector<int> Ans;Ans.clear();
	Ans.push_back(0);
	for(int i=1;i<=n;++i)
	{
		int x;
		scanf("%d",&x);
		if(x<0)
		{
			if(!s.count(-x)){yes=0;break;}
			s.erase(-x),used.insert(-x);
		}
		else
		{
			if(s.count(x)){yes=0;break;}
			s.insert(x);
		}
		if(s.count(abs(x))&&used.count(abs(x)))yes=0;
		if(s.empty())Ans.push_back(i),used.clear();
	}
	if(!s.empty())yes=0; 
	if(!yes)
	{
		puts("-1");
		return 0;
	}
	printf("%d\n",Ans.size()-1);
	for(int i=1;i<Ans.size();++i)printf("%d ",Ans[i]-Ans[i-1]);
}