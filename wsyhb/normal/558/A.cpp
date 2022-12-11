#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100+5;
struct node
{
	int x,a;
}l[N],r[N];
bool cmp(node p,node q)
{
	return p.x<q.x;
}
int s1[N],s2[N];
int main()
{
	int n,cnt1=0,cnt2=0;
	scanf("%d",&n);
	while(n--)
	{
		int x,a;
		scanf("%d%d",&x,&a);
		if(x>0) r[++cnt2]=node{x,a};
		else l[++cnt1]=node{-x,a};
	}
	sort(l+1,l+cnt1+1,cmp);
	sort(r+1,r+cnt2+1,cmp);
	for(int i=1;i<=cnt1;i++) s1[i]=s1[i-1]+l[i].a;
	for(int i=1;i<=cnt2;i++) s2[i]=s2[i-1]+r[i].a;
	ll ans=0;
	if(cnt1<cnt2) ans=s1[cnt1]+s2[cnt1+1];
	if(cnt1==cnt2) ans=s1[cnt1]+s2[cnt2];
	if(cnt1>cnt2) ans=s1[cnt2+1]+s2[cnt2];
	printf("%lld",ans);
	return 0;
}