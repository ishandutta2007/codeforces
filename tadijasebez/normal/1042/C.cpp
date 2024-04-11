#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=200050;
int a[N];
vector<int> zero,neg,pos;
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%i",&a[i]);
		if(a[i]==0) zero.pb(i);
		else if(a[i]<0) neg.pb(i);
		else pos.pb(i);
	}
	if(neg.size()%2==1)
	{
		int j=0;vector<int> tmp;
		for(i:neg) if(!j || a[j]<a[i]) j=i;
		for(i:neg) if(i!=j) tmp.pb(i);
		neg=tmp;
		zero.pb(j);
	}
	if(zero.empty() && (neg.size()%2==0))
	{
		for(i=1;i<n;i++) printf("1 %i %i\n",i,n);
		return 0;
	}
	if(zero.empty())
	{
		printf("2 %i\n",neg.back());
		int ed=n;
		if(neg.back()==n) ed=n-1;
		for(i=1;i<=n;i++) if(i!=ed && i!=neg.back()) printf("1 %i %i\n",i,ed);
		return 0;
	}
	if(pos.empty() && neg.size()<2)
	{
		for(i=1;i<n;i++) printf("1 %i %i\n",i,n);
		return 0;
	}
	int sk=zero.back();
	for(i=0;i+1<zero.size();i++) printf("1 %i %i\n",zero[i],sk);
	if(neg.size()%2==1) printf("1 %i %i\n",neg.back(),sk),neg.pop_back();
	printf("2 %i\n",sk);
	int st=pos.size()?pos.back():neg.back();
	for(i:pos) if(i!=st) printf("1 %i %i\n",i,st);
	for(i:neg) if(i!=st) printf("1 %i %i\n",i,st);
	return 0;
}