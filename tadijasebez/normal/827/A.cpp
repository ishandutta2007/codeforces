#include <stdio.h>
#include <set>
#include <cstring>
using namespace std;
const int N=2000500;
char word[N],sol[N];
set<int> Set;
set<int>::iterator it;
void Consider(int n, int pos)
{
	while(1)
	{
		it=Set.lower_bound(pos);
		if(it==Set.end()) return;
		if(*it-pos>=n) return;
		sol[*it]=word[*it-pos];
		Set.erase(*it);
	}
}
int max(int a, int b){ return a>b?a:b;}
int main()
{
	int i,n,k,x,m=0,l;
	for(i=1;i<N;i++) Set.insert(i);
	scanf("%i",&n);
	while(n--){
		scanf("%s",&word);
		l=(unsigned) strlen(word);
		scanf("%i",&k);
		while(k--){
			scanf("%i",&x);
			Consider(l,x);
			m=max(m,x+l-1);
		}
	}
	for(i=1;i<=m;i++){
		if(!Set.count(i)) printf("%c",sol[i]);
		else printf("a");
	}
	return 0;
}