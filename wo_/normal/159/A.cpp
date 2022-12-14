#include<cstdio>
#include<iostream>
#include<string>
#include<utility>
#include<set>
#include<algorithm>

using namespace std;

string name1[1100],name2[1100];
int time[1100];

typedef pair<string,string> P;

set<P> all;

int main()
{
	int n,d;
	cin>>n>>d;
	for(int i=0;i<n;i++)
	{
		cin>>name1[i]>>name2[i]>>time[i];
	}
	for(int i=0;i<n;i++)
	{
		int start=time[i];
		for(int j=i+1;j<n;j++)
		{
			if(time[j]-start>d)
			{
				break;
			}
			if(time[j]==start) continue;
			if(name1[i]==name2[j]&&name1[j]==name2[i])
			{
				string f=min(name1[i],name2[i]),s=max(name1[i],name2[i]);
				all.insert(P(f,s));
			}
		}
	}
	cout<<all.size()<<"\n";
	//printf("%d\n",all.size());
	for(set<P>::iterator it=all.begin();it!=all.end();it++)
	{
		cout<<(*it).first<<" "<<(*it).second<<"\n";
	}
	return 0;
}