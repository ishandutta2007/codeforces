#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<map>
#define X first
#define Y second
#include<set>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
typedef pair<int,int>ii;
map<string,int>g;
set<ii>ss;
vector<int>a[10020];
string sa,sb;
vector<ii>b;
int z[10020],zz[10020];
int Q(const string &s)
{
	if(g.count(s))
		return g[s];
	int t=g.size();
	return g[s]=t;
}
int n;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		cin>>sa>>sb;
		int ra=Q(sa),rb=Q(sb);
		a[ra].push_back(rb);
		a[rb].push_back(ra);
		if(ra<rb)
			swap(ra,rb);
		ss.insert(ii(ra,rb));
	}
	int n=g.size();
	for(int i=0;i<n;i++)
	{
		fe(j,a[i])
			fe(k,a[i])
				if(*j>*k)
					if(!ss.count(ii(*j,*k)))
						b.push_back(ii(*j,*k));
	}
	sort(b.begin(),b.end());
	memset(z,-1,sizeof z);
	for(int i=0,j;i<b.size();i=j)
	{
		for(j=i;j<b.size()&&b[j]==b[i];j++)
			;
		if(j-i>z[b[i].X])
		{
			z[b[i].X]=j-i;
			zz[b[i].X]=1;
		}
		else if(j-i==z[b[i].X])
			zz[b[i].X]++;
		if(j-i>z[b[i].Y])
		{
			z[b[i].Y]=j-i;
			zz[b[i].Y]=1;
		}
		else if(j-i==z[b[i].Y])
			zz[b[i].Y]++;		
	}
	cout<<g.size()<<endl;
	fe(i,g)
	{
		if(zz[i->Y]==0)
			zz[i->Y]=n-1-a[i->Y].size();
		cout<<i->X<<' '<<zz[i->Y]<<endl;
	}
	return 0;
}