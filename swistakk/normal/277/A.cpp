#include <iostream>

#include <vector>
//#include <cstdio>
#include <set>
#include <utility>
#include <map>
#include <algorithm>
#define N 205
#define uint long long int

using namespace std;
int byli[N];
int rep[N];
int find(int v)
{
	if(rep[v]==v)
	{
		return v;
	}
	int akt=find(rep[v]);
	rep[v]=akt;
	return akt;
}
void Union(int a, int b)
{
	int fa=find(a);
	int fb=find(b);
	if(fa==fb) return;
	rep[fb]=fa;
}
int main()
{
	ios_base::sync_with_stdio(0);
	int s=0;
	int n, l;
	cin>>n>>l;
	for(int i=1; i<=n+l; i++)
	{
		rep[i]=i;
	}
	for(int i=1; i<=n; i++)
	{
		rep[i]=i;
		int licz;
		cin>>licz;
		s+=licz;
		for(int j=1; j<=licz; j++)
		{
			int jez;
			cin>>jez;
			Union(i, n+jez);
		}
	}
	if(s==0)
	{
		cout<<n<<endl;
		return 0;
	}
	int wynik=0;
	for(int i=1; i<=n; i++)
	{
		int nic=find(i);
		if(byli[rep[i]]==0)
		{
			wynik++;
			byli[rep[i]]=1;
		}
	}
	cout<<wynik-1<<endl;
	return 0;
}