#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#define X first
#define Y second
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
int a[100020];
int pa[100020];
int b[100020];
int pb[100020];
int d[100020];
int l[100020];
int r[100020];
queue<int>q;
multiset<int>s;
pair<int,int>fk[100020];
int n;
int ri(int x)
{
	return (x+n-1)%n+1;
}
int main()
{
	scanf("%d",&n);
	fo(i,n)
		scanf("%d",a+i),pa[a[i]]=i;
	fo(i,n)
		scanf("%d",b+i),pb[b[i]]=i;
	memset(d,0x3f,sizeof d);
	fo(i,n)
	{
		
		int p=(pb[i]-pa[i]+n)%n+1;
		fk[i-1]=make_pair(ri(pb[i]+1),p);
		if(fk[i-1].Y<fk[i-1].X)
			fk[i-1].Y+=n;
	}
	s.insert(0x3f3f3f3f);
	s.insert(-0x3f3f3f3f);
	sort(fk,fk+n);
	int k=0,l=0;
	fo(i,2*n)
	{
		while(k<n&&fk[k].X<=i)
			s.insert(fk[k++].Y);
		while(l<n&&fk[l].X<=i-n)
			s.erase(s.find(fk[l++].Y));
		int A=*s.lower_bound(i);
		int B=*--s.lower_bound(i);
		d[ri(i)]=min(d[ri(i)],min(A-i,i-B));
	}
	fo(i,n)
		printf("%d\n",d[i]);
	return 0;
}