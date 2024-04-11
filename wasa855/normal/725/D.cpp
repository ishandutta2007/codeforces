#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define less lesss
struct team_more
{
	ull weight;
	ull balloon;
	bool operator < (team_more x) const
	{
		return (weight-balloon)>x.weight-x.balloon;
	}
};
struct team_less
{
	ull weight;
	ull balloon;
	bool operator < (team_less x) const
	{
		return balloon<x.balloon;
	}
};
struct team
{
	ull weight;
	ull balloon;
};
priority_queue<team_more> more;
priority_queue<team_less> less;
int main()
{
	team_more t1;
	team_less t2;
	team me;
	team t;
	int m;
	cin>>m;
	int ans=1;
	scanf("%lld %lld",&me.balloon,&me.weight);
	for(int i=2;i<=m;i++)
	{
		scanf("%lld %lld",&t.balloon,&t.weight);
		if(t.balloon<=me.balloon)
		{
			t2.balloon=t.balloon;
			t2.weight=t.weight;
			less.push(t2);
		}
		else
		{
			t1.balloon=t.balloon;
			t1.weight=t.weight;
			more.push(t1);
			ans++;
		}
	}
	int minn=ans;
	while(me.balloon>=0&&more.size()!=0)
	{
		t1=more.top();
//		printf("NOW more top : %lld %lld\n",t1.weight,t1.weight);
		if(t1.weight-t1.balloon+1>me.balloon)
		{
			break;
		}
		me.balloon-=(t1.weight-t1.balloon+1);
		ans--;
		more.pop();
//		cout<<less.top().balloon<<endl;
		while(less.size()!=0&&less.top().balloon>me.balloon)
		{
			t2=less.top();
			less.pop();
//			printf("NOW less top : %lld %lld\n",t2.weight,t2.weight);
			t1.balloon=t2.balloon;
			t1.weight=t2.weight; 
			more.push(t1);
			ans++;
		}
		if(ans<minn)
		{
			minn=ans;
//			cout<<"NOW ANSWER : "<<minn<<endl;
		}
	}
	cout<<minn<<endl;
	return 0;
}