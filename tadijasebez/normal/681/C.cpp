#include <stdio.h>
#include <cstring>
#include <queue>
#include <functional>
using namespace std;
priority_queue<int, vector<int> , greater<int> > pq;
vector< pair<int,int> > sol;
char t[20];
int main()
{
	int n,x,i;
	scanf("%i",&n);
	while(n--)
	{
		scanf("%s",&t);
		if(t[0]=='r')
		{
			if(pq.empty()) sol.push_back(make_pair(2,69));
			else pq.pop();
			sol.push_back(make_pair(1,0));
		}
		if(t[0]=='i')
		{
			scanf("%i",&x);
			sol.push_back(make_pair(2,x));
			pq.push(x);
		}
		if(t[0]=='g')
		{
			scanf("%i",&x);
			if(pq.empty()){
				sol.push_back(make_pair(2,x));
				pq.push(x);
			}
			else
			{
				while(!pq.empty() && pq.top()<x){
					sol.push_back(make_pair(1,0));
					pq.pop();
				}
				if(!(!pq.empty() && pq.top()==x)) sol.push_back(make_pair(2,x)),pq.push(x);
			}
			sol.push_back(make_pair(3,x));
		}
	}
	printf("%i\n",sol.size());
	for(i=0;i<sol.size();i++)
	{
		if(sol[i].first==1) printf("removeMin\n");
		if(sol[i].first==2) printf("insert %i\n",sol[i].second);
		if(sol[i].first==3) printf("getMin %i\n",sol[i].second);
	}
	return 0;
}