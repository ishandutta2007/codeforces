#include<bits/stdc++.h>
using namespace std;
vector<int> num;
typedef pair<int,int> P;
vector<P> ans;
void solve(int n,int coef)
{
//	fprintf(stderr,"n=%d coef=%d\n",n,coef);
	if(n<=2) // n may be 0
	{
		for(int i=1;i<=n;++i)
			num.push_back(i*coef);
		return;
	}
	int p=1;
	while(p<=n)
		p<<=1;
	p>>=1;
	if(p==n)
	{
		solve(n-1,coef);
		num.push_back(n*coef);
		return;
	}
	for(int i=1;i<=n-p;++i)
	{
		ans.push_back(P((p-i)*coef,(p+i)*coef));
		num.push_back(2*p*coef);
	}
	solve(p-(n-p)-1,coef);
	solve(n-p,coef<<1);
	num.push_back(p*coef);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		if(n==2)
		{
			puts("-1");
			continue;
		}
		num.clear();
		ans.clear();
		solve(n,1);
		assert((int)num.size()==n);
		sort(num.begin(),num.end());
		int answer=1;
		while(answer<n)
			answer<<=1;
		bool flag=false;
		for(int i=0;i+1<n&&num[i]<answer;++i)
		{
			if(num[i]==num[i+1])
			{
				flag=true;
				ans.push_back(P(num[i],num[i+1]));
				num[i]<<=1;
				num.erase(num.begin()+(i+1));
				break;
			}
		}
		assert(flag);
		for(int i=0;i<n-1;++i)
		{
			int x=num[i];
			while(x<answer)
			{
				ans.push_back(P(0,x));
				ans.push_back(P(x,x));
				x<<=1;
			}
			assert(x==answer);
		}
		ans.push_back(P(0,answer));
		printf("%d\n",(int)ans.size());
		for(vector<P>::iterator it=ans.begin();it!=ans.end();++it)
			printf("%d %d\n",it->first,it->second);
	}
	return 0;
}