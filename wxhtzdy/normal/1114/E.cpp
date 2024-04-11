#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int n,mx,Q;
int gcd(int x,int y)
{
	if(x==0) return y;
	return gcd(y%x,x);
}
int askG(int x)
{
	Q++;
	printf("> %d\n",x);
	fflush(stdout);
	int ret;
	scanf("%d",&ret);
	return ret;
}
int askP(int x)
{
	Q++;
	printf("? %d\n",x);
	fflush(stdout);
	int ret;
	scanf("%d",&ret);
	return ret;
}
void findMax()
{
	int l=0,r=INF,ans=0;
	while(l<=r)
	{
		int m=(l+r)/2;
		if(askG(m)) ans=m,l=m+1;
		else r=m-1;
	}
	mx=ans+1;
}
int main()
{
	scanf("%d",&n);
	findMax();
	vector<int> vec(1,mx);
	mt19937 rng(time(0));
	while(Q<60)
	{
		int i=rng()%n;
		vec.push_back(askP(i+1));
	}
	int d=0;
	sort(vec.begin(),vec.end());
	for(int i=0;i+1<vec.size();i++) d=gcd(d,vec[i+1]-vec[i]);
	printf("! %d %d\n",mx-d*(n-1),d);
	fflush(stdout);
	return 0;
}