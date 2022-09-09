#include <stdio.h>
#include <cstring>
#include <set>
#include <iostream>
#include <vector>
using namespace std;
const int N=100050;
set<string> A,B,AB,BA,FA,FB;
string Files[N];
int Type[N];
vector< pair<string,string> > sol;
int main()
{
	int n,i,e=0;
	scanf("%i",&n);
	for(i=0;i<n;i++)
	{
		cin >> Files[i];
		scanf("%i",&Type[i]);
		e+=Type[i];
	}
	for(i=1;i<=e;i++) A.insert(to_string(i));
	for(i=e+1;i<=n;i++) B.insert(to_string(i));
	for(i=0;i<n;i++)
	{
		if(A.count(Files[i])>0)
		{
			A.erase(Files[i]);
			if(Type[i]==0) AB.insert(Files[i]);
		}
		else if(B.count(Files[i])>0)
		{
			B.erase(Files[i]);
			if(Type[i]==1) BA.insert(Files[i]);
		}
		else if(Type[i]==1)
		{
			FA.insert(Files[i]);
		}
		else FB.insert(Files[i]);
	}
	set<string>::iterator it1,it2;
	while(!AB.empty() || !BA.empty() || !FA.empty() || !FB.empty())
	{
		if(!A.empty() && !BA.empty())
		{
			it1=A.begin();
			it2=BA.begin();
			sol.push_back(make_pair(*it2,*it1));
			A.erase(*it1);
			B.insert(*it2);
			BA.erase(*it2);
		}
		else if(!B.empty() && !AB.empty())
		{
			it1=B.begin();
			it2=AB.begin();
			sol.push_back(make_pair(*it2,*it1));
			B.erase(*it1);
			A.insert(*it2);
			AB.erase(*it2);
		}
		else if(!A.empty() && !FA.empty())
		{
			it1=A.begin();
			it2=FA.begin();
			sol.push_back(make_pair(*it2,*it1));
			A.erase(*it1);
			FA.erase(*it2);
		}
		else if(!B.empty() && !FB.empty())
		{
			it1=B.begin();
			it2=FB.begin();
			sol.push_back(make_pair(*it2,*it1));
			B.erase(*it1);
			FB.erase(*it2);
		}
		else
		{
			it1=AB.begin();
			sol.push_back(make_pair(*it1,"tmp"));
			FB.insert("tmp");
			A.insert(*it1);
			AB.erase(*it1);
		}
	}
	printf("%i\n",sol.size());
	for(i=0;i<sol.size();i++)
	{
		printf("move ");
		cout << sol[i].first;
		printf(" ");
		cout << sol[i].second;
		printf("\n");
	}
	return 0;
}