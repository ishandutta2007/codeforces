#include<bits/stdc++.h>
using namespace std;
struct m
{
	int s,x;
};
m w[1005];
bool cmp(m p,m q)
{
	if(p.s!=q.s) return p.s>q.s;
	return p.x<q.x;
}
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int n,i,a,b,c,d;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a>>b>>c>>d;
		w[i].s=a+b+c+d;
		w[i].x=i;
	}
	sort(w+1,w+n+1,cmp);
	for(i=1;i<=n;i++)
		if(w[i].x==1)
		{
			cout<<i;
			return 0;
		}
	return 0;
}