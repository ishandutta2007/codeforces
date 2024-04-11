#include <bits/stdc++.h>
using namespace std;

struct devices{
	long long int a;
	long long int b;
	double t;
};

bool acompare(devices lhs, devices rhs) { return lhs.t < rhs.t; }

int main(){
	int n,p;
	cin>>n>>p;
	devices d[n];
	long long int xx,ans,sum=0;

	for (int i = 0; i < n; ++i)
	{
		cin>>d[i].a>>d[i].b;
		d[i].t=d[i].b*1.0/d[i].a;
		sum+=d[i].a;
	}
	if (p>=sum)
	{
		cout<<-1;
		return 0;
	}
	if (n==1)
	{
		cout<<d[0].b*1.0/(d[0].a-p);
		return 0;
	}
	sort(d,d+n,acompare);
	
	devices s;
	s.a=0;
	s.b=0;
	s.t=d[0].t;
	int i=0;
	while(d[i].t==s.t){
		s.a+=d[i].a;
		s.b+=d[i].b;
		i++;
		if (i==n)
		{
			break;
		}
	}
	double x,xxx;
	x =1;
	
			 xx=s.a-p;
			ans=s.b;
			xxx=x*ans/xx;
	if (i<n)
	{
	
		while((p>=s.a)||(d[i].t<(xxx))||(d[i].t==d[i-1].t)){
			s.a+=d[i].a;
			s.b+=d[i].b;
			i++;
			if (i==n)
			{
				break;
			}
			x =1;
	
			 xx=s.a-p;
			ans=s.b;
			xxx=x*ans/xx;
		}
	}
	 x =1;
	
	 xx=s.a-p;
	ans=s.b;
	xxx=x*ans/xx;
	if ((xxx>.99980)&&(xxx<.99982))
	{
		cout<<d[i].t<<"  "<<(s.b/(s.a-p))<<" "<<p<< endl;
	}
	cout<<xxx;

	return 0;
}