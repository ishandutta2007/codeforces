#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<queue>
#include<set>
#define X first
#define Y second
using namespace std;
typedef pair<int,int>ii;
typedef long long ll;
ll l[255555];
ll d[255555];
int v[255555];
int m[255555];
int p[255555];
int r[255555];
set<ii>s[255555];
int x,y,p0,r0,n,xi,yi,z;
queue<ii>q;
set<ii>::iterator it;
int main()
{
	scanf("%d %d %d %d %d",&x,&y,&p0,&r0,&n),p0*=-1;
	for(int i=0;i<n;i++)
	{
		scanf("%d %d %d %d %d",&xi,&yi,&m[i],&p[i],&r[i]);
		m[i]*=-1,p[i]*=-1,xi-=x,yi-=y,d[i]=l[i]=(ll)xi*xi+(ll)yi*yi;
	}
	sort(l,l+n);
	int lc=unique(l,l+n)-l;
	for(int i=0;i<n;i++)
		v[i]=lower_bound(l,l+lc,d[i])-l+1;
	for(int i=0;i<n;i++)
		for(int j=v[i];j<=lc;j+=j&-j)
			s[j].insert(ii(m[i],i));
	q.push(ii(p0,r0));
	while(!q.empty())
	{
		ii x=q.front();
		q.pop();
		x.Y=upper_bound(l,l+lc,(ll)x.Y*x.Y)-l;
		for(int i=x.Y;i;i-=i&-i)
		{
			while((it=s[i].lower_bound(ii(x.X,-1)))!=s[i].end())
			{
				z++;
				int w=it->Y;
				q.push(ii(p[w],r[w]));
				for(int j=v[w];j<=lc;j+=j&-j)
					s[j].erase(ii(m[w],w));
			}
		}
	}
	printf("%d\n",z);
	return 0;
}