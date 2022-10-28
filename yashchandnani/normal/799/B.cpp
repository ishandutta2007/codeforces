#include <bits/stdc++.h>
using namespace std;

int min(int a,int b,int c){
	if (a<b)
	{
		if (a<c)
		{
			return 1;
		}
		else{
			return 3;
		}
	}
	if (b<c)
	{
		return 2;
	}
	return 3;
}

int main()
{
	int n,m,temp,temp1,temp2;
	vector<int> c;
	std::vector<int> a;
	std::vector<int> b;
	vector<int> c2;
	std::vector<int> a2;
	std::vector<int> b2;
	vector<int> d;
	vector<int> e;
	vector<int> p;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>temp;
		p.push_back(temp);
	}
	for (int i = 0; i < n; ++i)
	{
		cin>>temp;
		e.push_back(temp);
	}
	for (int i = 0; i < n; ++i)
	{
		cin>>temp;
		d.push_back(temp);
	}

	for (int i = 0; i < n; ++i)
	{
		temp=p[i];
		
		temp1=d[i];

		temp2=e[i];
		if (temp1==temp2)
		{
			if (temp1==1)
			{
				a2.push_back(temp);
			}
			else if (temp1==2)
			{
				b2.push_back(temp);
			}
			else{
				c2.push_back(temp);
			}
		}
		else if (temp1+temp2==3)
		{
			a.push_back(temp);
		}
		else if (temp1+temp2==4)
		{
			b.push_back(temp);
		}
		else{
			c.push_back(temp);
		}
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	sort(c.begin(),c.end());
	sort(a2.begin(),a2.end());
	sort(b2.begin(),b2.end());
	sort(c2.begin(),c2.end());
	a.push_back(1000000009);
	b.push_back(1000000009);
	c.push_back(1000000009);
	a2.push_back(1000000009);
	b2.push_back(1000000009);
	c2.push_back(1000000009);

	int a1=0,b1=0,c1=0,a3=0,b3=0,c3=0;
	cin>>m;
	for (int i = 0; i < m; ++i)
	{
		cin>>temp;
		if (temp==1)
		{
			int x=min(a[a1],b[b1],a2[a3]);
			if (x==1)
			{
				
				cout<<a[a1]<<" ";
				a1++;

			}
			else if (x==2)
			{
				
				cout<<b[b1]<<" ";
				b1++;
			}
			else if (a2[a3]==1000000009)
			{
				cout<<-1<<" ";
			}
			else{
				cout<<a2[a3]<<" ";
				a3++;
			}
		}
		else if (temp==2)
		{
			int x=min(a[a1],c[c1],b2[b3]);

			if (x==1)
			{
				
				cout<<a[a1]<<" ";
				a1++;

			}
			else if (x==2)
			{
				
				cout<<c[c1]<<" ";
				c1++;
			}
			else if (b2[b3]==1000000009)
			{
				cout<<-1<<" ";
			}
			else{
				cout<<b2[b3]<<" ";
				b3++;
			}
		}
		else if (temp==3)
		{
			int x=min(c[c1],b[b1],c2[c3]);
			if (x==1)
			{
				
				cout<<c[c1]<<" ";
				c1++;

			}
			else if (x==2)
			{
				
				cout<<b[b1]<<" ";
				b1++;
			}
			else if (c2[c3]==1000000009)
			{
				cout<<-1<<" ";
			}
			else{
				cout<<c2[c3]<<" ";
				c3++;
			}
		}

	}

	
	return 0;
}