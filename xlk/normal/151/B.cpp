#include<iostream>
#include<string>
#include<stdio.h>
#include<vector>
using namespace std;
int n,m;
vector<string>a,b,c;
string s,nam,tel;
int v[4];
int w[4];
int main()
{
	int i;
	cin>>n;
	while(n--)
	{
		cin>>m;
		cin>>nam;
		v[1]=v[2]=v[3]=0;
		while(m--)
		{
			cin>>tel;
			if(tel[0]==tel[1]&&tel[0]==tel[3]&&tel[0]==tel[4]&&tel[0]==tel[6]&&tel[0]==tel[7])
				v[1]++;
			else if(tel[0]>tel[1]&&tel[1]>tel[3]&&tel[3]>tel[4]&&tel[4]>tel[6]&&tel[6]>tel[7])
				v[2]++;
			else
				v[3]++;
		}
		if(w[1]<v[1])
			w[1]=v[1],a.clear();
		if(w[1]==v[1])
			a.push_back(nam);
		if(w[2]<v[2])
			w[2]=v[2],b.clear();
		if(w[2]==v[2])
			b.push_back(nam);
		if(w[3]<v[3])
			w[3]=v[3],c.clear();
		if(w[3]==v[3])
			c.push_back(nam);
	}
	cout<<"If you want to call a taxi, you should call: ";
	for(i=0;i<a.size()-1;i++)
		cout<<a[i]<<", ";
	cout<<a[i]<<".\n";
	cout<<"If you want to order a pizza, you should call: ";
	for(i=0;i<b.size()-1;i++)
		cout<<b[i]<<", ";
	cout<<b[i]<<".\n";
	cout<<"If you want to go to a cafe with a wonderful girl, you should call: ";
	for(i=0;i<c.size()-1;i++)
		cout<<c[i]<<", ";
	cout<<c[i]<<".\n";
	return 0;
}