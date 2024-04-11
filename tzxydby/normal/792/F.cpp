#include<bits/stdc++.h>
using namespace std;
const int N=100005,mod=1000000;
struct pt{double x,y;};
pt operator-(pt a,pt b){return {a.x-b.x,a.y-b.y};}
double operator*(pt a,pt b){return a.x*b.y-a.y*b.x;}
bool operator<(pt a,pt b){return a.x==b.x?a.y<b.y:a.x<b.x;}
int q,l;
long long m;
set<pt>s;
void ins(double x,double y)
{
	pt p={x,y};
	if(s.count(p))
		return;
	auto it=s.lower_bound({x,0});
	auto pr=it;pr--;
	if(it!=s.end()&&(p-*pr)*(*it-p)<=0)
		return;
	s.insert(p);
	pr=s.lower_bound(p);pr--;
	auto z=pr;z--;
	while(pr!=s.begin()&&(*pr-*z)*(p-*pr)<=0)
		s.erase(pr),pr=z,z--;
}
int chk(double x,double y)
{
	pt p={x,y};
	auto it=s.lower_bound({x,0});
	if(it==s.end())
		return 0;
	auto pr=it;pr--;
	if((*it-*pr)*(p-*pr)>-(1e-9))
		return 1;
	else
		return 0;
}
int main()
{
	scanf("%d%lld",&q,&m);
	s.insert({0,0});
	for(int i=1;i<=q;i++)
	{
		int k,a,b;
		scanf("%d%d%d",&k,&a,&b);
		a=(a+l)%mod+1,b=(b+l)%mod+1;
		if(k==1)
			ins(a,b);
		else
		{
			if(chk(1.0*b/a,1.0*m/a))
			{
				puts("YES");
				l=i;
			}
			else
				puts("NO");
		}
	}
	return 0;
}