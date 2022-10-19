#include<bits/stdc++.h>
using namespace std;
struct team
{
	string name;
	int rating;
}t[70];
bool cmp(team x,team y)
{
	return x.rating>y.rating;
}
vector<team>basket[4];
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,x,a,b,c,k;
	char kase='A';
	cin>>n>>x>>a>>b>>c;
	for(int i=0;i<n;i++)
		cin>>t[i].name>>t[i].rating;
	sort(t,t+n,cmp);
	for(int i=0;i<4;i++)
		for(int j=0;j<n/4;j++)
			basket[i].push_back(t[i*n/4+j]);
	for(int j=4;j<n;j+=4)
	{
		printf("Group %c:\n",kase++);
		for(int i=0;i<4;i++)
		{
			x=(x*a+b)%c;
			k=x;
			k%=basket[i].size();
			cout<<basket[i][k].name<<endl;
			basket[i].erase(basket[i].begin()+k);
		}
	}
	printf("Group %c:\n",kase);
	for(int i=0;i<4;i++)
		cout<<basket[i][0].name<<endl;
	return 0;
}