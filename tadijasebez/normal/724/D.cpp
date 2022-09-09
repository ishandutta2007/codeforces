#include <stdio.h>
#include <set>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
set<int> Set;
set<int>::iterator it,it1,it2,it3;
vector<int> v,u;
const int N=100050;
vector<int> C[26];
char word[N];
int main()
{
	int m,n,i,j;
	scanf("%i",&m);
	scanf("%s",&word);
	n=strlen(word);
	for(i=0;i<n;i++) C[word[i]-'a'].push_back(i+1);
	Set.insert(0);
	Set.insert(n+1);
	for(j=0;j<26;j++)
	{
		for(i=0;i<C[j].size();i++)
		{
			int c=C[j][i];
			Set.insert(c);
			it=Set.find(c);
			it1=it;it1++;
			it2=it;it2--;
			if(*it2 && word[*it2-1]==word[c-1])
			{
				it3=it2;it3--;
				if(c-(*it3)<=m) u.push_back(*it2),Set.erase(*it2);
				else if((*it1)-(*it2)>m) v.push_back(j);
				else u.push_back(c),Set.erase(c);
			}
			else
			{
				if((*it1)-(*it2)>m) v.push_back(j);
				else u.push_back(c),Set.erase(c);
			}
		}
		it1=Set.begin();
		it2=it1;
		bool ok=true;
		for(it2++;it2!=Set.end();it2++)
		{
			//printf("%i %i %i\n",j,*it2,*it1);
			if((*it2)-(*it1)>m) ok=false;
			it1=it2;
		}
		if(ok) break;
		for(i=0;i<u.size();i++)
		{
			v.push_back(j);
			Set.insert(u[i]);
		}
		u.clear();
	}
	for(i=0;i<v.size();i++) printf("%c",v[i]+'a');
	printf("\n");
	return 0;
}