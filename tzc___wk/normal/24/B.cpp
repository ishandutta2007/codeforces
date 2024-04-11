#include <bits/stdc++.h>
#include <map>
#include <string>
using namespace std;
int sc[10]={25,18,15,12,10,8,6,4,2,1};
struct racer
{
	int p;
	int w[55];
};
int z,n;
map<string,racer> r;
bool b1(const racer &r1,const racer &r2)
{
	if(r1.p!=r2.p)	return r1.p>r2.p;
	for(int i=0;i<55;i++)
	{
		if(r1.w[i]!=r2.w[i])	return r1.w[i]>r2.w[i];
	}
	return false;
}
bool b2(const racer &r1,const racer &r2)
{
	if(r1.w[0]!=r2.w[0])	return r1.w[0]>r2.w[0];
	return b1(r1,r2);
}
string s;
int main()
{
	cin>>z;
	for(int zz=0;zz<z;zz++)
	{
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>s;
			int cnt=0;
			if(i<10)	r[s].p+=sc[i];
			r[s].w[i]++;
		}
	}
	string ans1=r.begin()->first,ans2=r.begin()->first;
	for(map<string,racer>::iterator it=r.begin();it!=r.end();it++)
	{
		if(b1(it->second,r[ans1]))	ans1=it->first;
		if(b2(it->second,r[ans2]))	ans2=it->first;
	}
	cout<<ans1<<endl<<ans2<<endl;
	return 0;
}