#include <stdio.h>
#include <set>
#include <algorithm>
#include <unordered_map>
using namespace std;
const int N=100050;
set<int> s;
unordered_map<int,bool> l,r;
int p[N];
int main()
{
	int n,i,a;
	scanf("%i",&n);
	scanf("%i",&a);
	s.insert(a);
	set<int>::iterator it;
	int left,right;
	l[0]=true;
	r[0]=true;
	for(i=1;i<n;i++)
	{
		scanf("%i",&a);
		it=s.upper_bound(a);
		if(it==s.end()) right=0;
		else right=*it;
		if(it==s.begin()) left=0;
		else it--,left=*it;
		if(r[left]) p[i]=right,l[right]=true;
		else p[i]=left,r[left]=true;
		s.insert(a);
	}
	for(i=1;i<n;i++) printf("%i ",p[i]);
	return 0;
}