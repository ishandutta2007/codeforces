#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define mp make_pair
vector<pair<int,int> > v;
const int N=100050;
int Q[N],K[N];
bool comp(pair<int,int> a, pair<int,int> b){return a.first>b.first;}
int main()
{
	int p,q,n,s,i;
	char t;
	scanf("%i %i",&n,&s);
	while(n--){
		scanf("\n%c %i %i",&t,&p,&q);
		if(t=='B') K[p]+=q;
		else Q[p]+=q;
	}
	int c=0;
	for(i=0;i<N;i++) if(Q[i]>0 && c<s) v.push_back(mp(i,Q[i])),c++;
	sort(v.begin(),v.end(),comp);
	for(i=0;i<v.size();i++) printf("S %i %i\n",v[i].first,v[i].second);
	c=0;
	for(i=N-1;i>=0;i--) if(K[i]>0 && c<s) printf("B %i %i\n",i,K[i]),c++;
	return 0;
}