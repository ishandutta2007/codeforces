#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
int a[1000005];
pair <int,double> s[1000005];
int cnt=0;
inline pair<int,double> hebing(pair<int,double> a,pair<int,double> b)
{
	return {a.first+b.first,(double)((double)a.first*a.second+(double)b.first*b.second)/(double)(a.first+b.first)};
}
inline void add(pair<int,double> x)
{
	pair<int,double> X=hebing(x,s[cnt]);
	if(X.second<s[cnt].second)
		s[cnt--]={0,0},add(X);
	else s[++cnt]=x;
}
signed main(int argc, char** argv) {
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{ 
		scanf("%d",&a[i]);
		pair <int,int> t={1,a[i]};
		add(t);
	}
	//cout << hebing({2,5},{1,7}).second << endl;
	for(int i=1;i<=cnt;i++)
		for(int j=1;j<=s[i].first;j++)
			printf("%.20lf\n",s[i].second);
	return 0;
}