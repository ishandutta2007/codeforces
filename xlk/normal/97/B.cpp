#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<set>
#define X first
#define Y second
using namespace std;
typedef pair<int,int>ii;
set<ii>s;
ii a[10020];
int n;
void F(int l,int r)
{
	if(l+1==r)
		return;
	int m=l+r>>1;
	for(int i=l;i<r;i++)
		s.insert(ii(a[m].X,a[i].Y));
	F(l,m),F(m,r);
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d %d",&a[i].X,&a[i].Y),s.insert(a[i]);
	sort(a,a+n);
	F(0,n);
	printf("%d\n",s.size());
	for(set<ii>::iterator i=s.begin();i!=s.end();i++)
		printf("%d %d\n",i->X,i->Y);
	return 0;
}