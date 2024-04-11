#include <bits/stdc++.h>
using namespace std;
int fruit[110];
map<string,int>	num;
map<int,int> amm;
map<string,bool> used;
int price[110],type=0;
string name[110];
int n,m;
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>price[i];
	}
	for(int i=0;i<m;i++)
	{
		cin>>name[i];
		if(used[name[i]]==false)
		{
			num[name[i]]=type;
			type++;
			used[name[i]]=true;
		}
		amm[num[name[i]]]++;
	}
	sort(price,price+n);
	//cout<<type<<endl;
	for(int i=0;i<type;i++)
	{
		fruit[i]=amm[i];
	}
	sort(fruit,fruit+type);
	//cout<<fruit[1]<<endl;
	int minn=0,maxx=0;
	for(int i=0;i<type;i++)
	{
		minn+=price[i]*fruit[type-1-i];
	}
	cout<<minn<<endl;
	for(int i=0;i<type;i++)
	{
		maxx+=fruit[i]*price[i+n-type];
	}
	cout<<maxx<<endl;
	return 0;
}