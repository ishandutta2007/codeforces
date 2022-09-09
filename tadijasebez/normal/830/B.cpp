#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
const int N=100050;
vector<int> X[N],id,order;
vector<int> q;
int a[N];
int BIT[N];
void Set(int i, int j){ for(;i<N;i+=i&-i) BIT[i]+=j;}
int Get(int i){ int ret=0;for(;i;i-=i&-i) ret+=BIT[i];return ret;}
int main()
{
	int n,i,j,m,p;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]),id.push_back(a[i]);
	sort(id.begin(),id.end());
	id.erase(unique(id.begin(),id.end()),id.end());
	m=id.size();
	for(i=1;i<=n;i++) a[i]=lower_bound(id.begin(),id.end(),a[i])-id.begin();
	for(i=1;i<=n;i++) X[a[i]].push_back(i);
	for(i=0;i<X[0].size();i++) order.push_back(X[0][i]),p=X[0][i];
	for(j=1;j<m;j++)
	{
		q.clear();
		i=0;
		while(i<X[j].size() && p>X[j][i]) q.push_back(X[j][i]),i++;
		for(;i<X[j].size();i++) order.push_back(X[j][i]),p=X[j][i];
		for(i=0;i<q.size();i++) order.push_back(q[i]),p=q[i];
	}
	long long sol=0;
	for(i=1;i<=n;i++) Set(i,1);
	sol=Get(order[0]);
	Set(order[0],-1);
	p=order[0];
	for(i=1;i<order.size();i++)
	{
		int c=order[i];
		if(p<c) sol+=Get(c)-Get(p);
		else sol+=Get(n)-Get(p)+Get(c);
		Set(c,-1);
		p=c;
	}
	printf("%lld\n",sol);
	return 0;
}