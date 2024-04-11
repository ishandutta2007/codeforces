#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
vector<pair<int,int> > ans;
pair<int,int> score;
void Output()
{
	printf("%i:%i\n",score.first,score.second);
	for(auto p:ans) printf("%i:%i ",p.first,p.second);
	printf("\n");
}
bool Check30(int a, int b)
{
	score=mp(3,0);
	ans.clear();
	ans.pb(mp(25,0));
	ans.pb(mp(25,0));
	ans.pb(mp(25,0));
	a-=75;
	if(a<0) return 0;
	if(a>0) ans[0].first+=a;
	ans[0].second=min(ans[0].first-2,b);
	b-=ans[0].second;
	ans[1].second=min(23,b);
	b-=ans[1].second;
	ans[2].second=min(23,b);
	b-=ans[2].second;
	if(b>0) return 0;
	if(ans[0].first>25 && ans[0].second!=ans[0].first-2) return 0;
	return 1;
}
bool Check31PumpB(int a, int b)
{
	score=mp(3,1);
	ans.clear();
	ans.pb(mp(0,25));
	ans.pb(mp(25,0));
	ans.pb(mp(25,0));
	ans.pb(mp(25,0));
	a-=75;b-=25;
	if(a<0 || b<0) return 0;
	ans[0].first=min(a,b+25-2);
	a-=ans[0].first;
	ans[0].second=ans[0].first+2;
	if(ans[0].second<25) return 0;
	b-=ans[0].second-25;
	for(int i=1;i<=3;i++)
	{
		ans[i].second=min(b,23);
		b-=ans[i].second;
	}
	if(b!=0 || a!=0) return 0;
	return 1;
}
bool Check31PumpA(int a, int b)
{
	score=mp(3,1);
	ans.clear();
	ans.pb(mp(0,25));
	ans.pb(mp(25,0));
	ans.pb(mp(25,0));
	ans.pb(mp(25,0));
	a-=75;b-=25;
	if(a<0 || b<0) return 0;
	ans[1].second=min(b,a+25-2);
	b-=ans[1].second;
	ans[1].first=ans[1].second+2;
	if(ans[1].first<25) return 0;
	a-=ans[1].first-25;
	for(int i=2;i<=3;i++)
	{
		ans[i].second=min(b,23);
		b-=ans[i].second;
	}
	ans[0].first=min(a,23);
	a-=ans[0].first;
	if(b!=0 || a!=0) return 0;
	return 1;
}
bool Check31NoPump(int a, int b)
{
	score=mp(3,1);
	ans.clear();
	ans.pb(mp(0,25));
	ans.pb(mp(25,0));
	ans.pb(mp(25,0));
	ans.pb(mp(25,0));
	a-=75;b-=25;
	if(a<0 || b<0) return 0;
	for(int i=1;i<=3;i++)
	{
		ans[i].second=min(b,23);
		b-=ans[i].second;
	}
	ans[0].first=min(a,23);
	a-=ans[0].first;
	if(b!=0 || a!=0) return 0;
	return 1;
}
bool Check31(int a, int b)
{
	if(Check31NoPump(a,b)) return 1;
	if(Check31PumpA(a,b)) return 1;
	if(Check31PumpB(a,b)) return 1;
	return 0;
}
bool Check32(int a, int b)
{
	score=mp(3,2);
	ans.clear();
	ans.pb(mp(0,25));
	ans.pb(mp(0,25));
	ans.pb(mp(25,0));
	ans.pb(mp(25,0));
	ans.pb(mp(15,0));
	a-=65;b-=50;
	if(a<0 || b<0) return 0;
	int pa=a,bp=b;
	//NoPump
	while(1)
	{
		for(int i=0;i<=1;i++)
		{
			ans[i].first=min(a,ans[i].second-2);
			a-=ans[i].first;
		}
		for(int i=2;i<5;i++)
		{
			ans[i].second=min(b,ans[i].first-2);
			b-=ans[i].second;
		}
		if(a!=0 || b!=0) break;
		return 1;
	}
	//PumpB
	a=pa;b=bp;
	ans.clear();
	ans.pb(mp(0,25));
	ans.pb(mp(0,25));
	ans.pb(mp(25,0));
	ans.pb(mp(25,0));
	ans.pb(mp(15,0));
	while(1)
	{
		ans[0].first=min(a,b+25-2);
		a-=ans[0].first;
		ans[0].second=ans[0].first+2;
		if(ans[0].second<25) break;
		b-=ans[0].second-25;
		if(a<0 || b<0) break;
		ans[1].first=min(a,23);
		a-=ans[1].first;
		for(int i=2;i<5;i++)
		{
			ans[i].second=min(ans[i].first-2,b);
			b-=ans[i].second;
		}
		if(a!=0 || b!=0) break;
		return 1;
	}
	//PumpA25
	a=pa;b=bp;
	ans.clear();
	ans.pb(mp(0,25));
	ans.pb(mp(0,25));
	ans.pb(mp(25,0));
	ans.pb(mp(25,0));
	ans.pb(mp(15,0));
	while(1)
	{
		ans[2].second=min(b,a+25-2);
		b-=ans[2].second;
		ans[2].first=ans[2].second+2;
		if(ans[2].first<25) break;
		a-=ans[2].first-25;
		if(a<0 || b<0) break;
		for(int i=0;i<=1;i++)
		{
			ans[i].first=min(a,ans[i].second-2);
			a-=ans[i].first;
		}
		for(int i=3;i<=4;i++)
		{
			ans[i].second=min(b,ans[i].first-2);
			b-=ans[i].second;
		}
		if(a!=0 || b!=0) break;
		return 1;
	}
	//PumpA15
	a=pa;b=bp;
	ans.clear();
	ans.pb(mp(0,25));
	ans.pb(mp(0,25));
	ans.pb(mp(25,0));
	ans.pb(mp(25,0));
	ans.pb(mp(15,0));
	while(1)
	{
		ans[4].second=min(b,a+15-2);
		b-=ans[4].second;
		ans[4].first=ans[4].second+2;
		if(ans[4].first<15) break;
		a-=ans[4].first-15;
		if(a<0 || b<0) break;
		for(int i=0;i<=1;i++)
		{
			ans[i].first=min(a,ans[i].second-2);
			a-=ans[i].first;
		}
		for(int i=2;i<=3;i++)
		{
			ans[i].second=min(b,ans[i].first-2);
			b-=ans[i].second;
		}
		if(a!=0 || b!=0) break;
		return 1;
	}
	if(a!=0 || b!=0) return 0;
	return 1;
}
void SwapAns()
{
	swap(score.first,score.second);
	for(int i=0;i<ans.size();i++)
	{
		swap(ans[i].first,ans[i].second);
	}
}
bool Check23(int a, int b)
{
	if(Check32(b,a))
	{
		SwapAns();
		return 1;
	}
	return 0;
}
bool Check13(int a, int b)
{
	if(Check31(b,a))
	{
		SwapAns();
		return 1;
	}
	return 0;
}
bool Check03(int a, int b)
{
	if(Check30(b,a))
	{
		SwapAns();
		return 1;
	}
	return 0;
}
int main()
{
	int n,i,a,b;
	scanf("%i",&n);
	while(n--)
	{
		scanf("%i %i",&a,&b);
		if(Check30(a,b)) Output();
		else if(Check31(a,b)) Output();
		else if(Check32(a,b)) Output();
		else if(Check23(a,b)) Output();
		else if(Check13(a,b)) Output();
		else if(Check03(a,b)) Output();
		else printf("Impossible\n");
	}
	return 0;
}