#include <stdio.h>
#include <map>
using namespace std;
map<int,int> cnt,cnt2;
int main()
{
	int n,x,i;
	scanf("%i",&n);
	for(i=0;i<n;i++) scanf("%i",&x),cnt[x]++;
	n--;
	for(i=0;i<n;i++) scanf("%i",&x),cnt[x]--,cnt2[x]++;
	n--;
	for(i=0;i<n;i++) scanf("%i",&x),cnt2[x]--;
	map<int,int>::iterator it;
	for(it=cnt.begin();it!=cnt.end();it++) for(i=0;i<it->second;i++) printf("%i\n",it->first);
	for(it=cnt2.begin();it!=cnt2.end();it++) for(i=0;i<it->second;i++) printf("%i\n",it->first);
	return 0;
}