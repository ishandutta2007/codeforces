#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
using namespace std;
#define mp make_pair
#define pb push_back
#define ll long int
const int N=100050;
const int M=2000050;
const int S=1415;
vector<int> Prime;
bool sieve[S];
void FindPrimes()
{
	int i,j;
	for(i=2;i<S;i++)
	{
		if(!sieve[i])
		{
			Prime.pb(i);
			for(j=i;j<S;j+=i) sieve[j]=1;
		}
	}
}
set<int> Set;
void Init()
{
	for(int i=2;i<M;i++) Set.insert(i);
}
bool out[M];
void Erase(int x)
{
	int i,j;
	for(i=0;i<Prime.size();i++)
	{
		if(x%Prime[i]==0)
		{
			while(x%Prime[i]==0) x/=Prime[i];
			//for(j=Prime[i];j<M;j+=Prime[i])
			//{
				out[Prime[i]]=1;
				//if(Set.count(j)) Set.erase(j);
			//}
		}
	}
	if(x>1)
	{
		out[x]=1;
		//for(j=x;j<M;j+=x)
		//{
			//out[j]=1;
			//if(Set.count(j)) Set.erase(j);
		//}
	}
}
bool Check(int x)
{
	int i,j;
	for(i=0;i<Prime.size();i++)
	{
		if(x%Prime[i]==0)
		{
			while(x%Prime[i]==0) x/=Prime[i];
			//for(j=Prime[i];j<M;j+=Prime[i])
			//{
				if(out[Prime[i]]==1) return 0;
				//if(Set.count(j)) Set.erase(j);
			//}
		}
	}
	if(x>1)
	{
		if(out[x]==1) return 0;
		//for(j=x;j<M;j+=x)
		//{
			//out[j]=1;
			//if(Set.count(j)) Set.erase(j);
		//}
	}
	return 1;
}
int a[N],b[N];
set<int>::iterator it;
int main()
{
	Init();
	FindPrimes();
	//printf("%i\n",Prime.size());
	int n,i,ptr=2;bool done=0;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%i",&a[i]);
		if(done)
		{
			a[i]=1;
			for(;!Check(ptr);ptr++);
			b[i]=ptr;
			Erase(b[i]);
			continue;
		}
		while(!Check(*Set.lower_bound(a[i])))
		{
			Set.erase(Set.lower_bound(a[i]));
		}
		b[i]=*Set.lower_bound(a[i]);
		Erase(b[i]);
		if(b[i]>a[i]) done=1;
	}
	for(i=1;i<=n;i++) printf("%i ",b[i]);
	return 0;
}