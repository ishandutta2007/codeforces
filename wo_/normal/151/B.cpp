#include<cstdio>
#include<iostream>
#include<vector>
#include<string>

using namespace std;

string name[110];
int taxi[110],pizza[110],girl[110];

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int t;
		cin>>t>>name[i];
		for(int j=0;j<t;j++)
		{
			string num;
			cin>>num;
			if(num[0]==num[1]&&num[1]==num[3]&&num[3]==num[4]&&num[4]==num[6]&&num[6]==num[7])
			{
				taxi[i]++;
			}
			else if(num[0]>num[1]&&num[1]>num[3]&&num[3]>num[4]&&num[4]>num[6]&&num[6]>num[7])
			{
				pizza[i]++;
			}
			else girl[i]++;
		}
	}
	vector<int> t,p,g;
	int tn=-1,pn=-1,gn=-1;
	for(int i=0;i<n;i++)
	{
		if(tn==taxi[i]) t.push_back(i);
		else if(tn<taxi[i])
		{
			tn=taxi[i];
			t.clear();
			t.push_back(i);
		}
		if(pn==pizza[i])
		{
			p.push_back(i);
		}
		else if(pn<pizza[i])
		{
			pn=pizza[i];
			p.clear();
			p.push_back(i);
		}
		if(gn==girl[i])
		{
			g.push_back(i);
		}
		else if(gn<girl[i])
		{
			gn=girl[i];
			g.clear();
			g.push_back(i);
		}
	}
	printf("If you want to call a taxi, you should call:");
	for(int i=0;i<t.size();i++)
	{
		printf(" ");
		cout<<name[t[i]];
		if(i==t.size()-1) printf(".\n");
		else printf(",");
	}
	printf("If you want to order a pizza, you should call:");
	for(int i=0;i<p.size();i++)
	{
		printf(" ");
		cout<<name[p[i]];
		if(i==p.size()-1) printf(".\n");
		else printf(",");
	}
	printf("If you want to go to a cafe with a wonderful girl, you should call:");
	for(int i=0;i<g.size();i++)
	{
		printf(" ");
		cout<<name[g[i]];
		if(i==g.size()-1) printf(".\n");
		else printf(",");
	}
	return 0;
}