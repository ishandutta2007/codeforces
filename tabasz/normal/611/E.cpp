#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
#define PII pair<int, int>
#define PLL pair<LL, LL>
#define pb pop_back

int n, r, res, tmp;
int a, b, c;
set<PII> S;

void go(int x)
{
	set<PII>::iterator it=S.lower_bound(MP(-x, 0));
	if(it!=S.end())
	{
		if(-(*it).F<=min(b+c, a))
			tmp--;
		S.erase(it);
	}
}

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d%d%d%d", &n, &a, &b, &c);
	if(a<c)
		swap(a, c);
	if(a<b)
		swap(a, b);
	if(b<c)
		swap(b, c);
	for(int i=0; i<n; i++)
	{
		int x;
		scanf("%d", &x);
		if(x>a+b+c)
		{
			printf("-1\n");
			return 0;
		}
		if(x>a+b)
			r++;
		else
			S.insert(MP(-x, i));
	}
	while(!S.empty() && -(*S.begin()).F>max(a, b+c))
	{
		PII x=*S.begin();
		S.erase(S.begin());
		if(-x.F>a+c)
			go(c);
		else
			go(b);
		r++;
	}
	tmp=0;
	for(set<PII>::iterator it=S.begin(); it!=S.end(); it++)
	{
		//printf("%d ", -(*it).F);
		if(-(*it).F<=min(a, b+c))
			tmp++;
	}
	//printf("\n");
	res=r+max(((int)S.size()+1)/2, (int)S.size()-tmp);
	//printf("%d %d %d\n", r, tmp, (int)S.size());
	
	while(!S.empty() && S.lower_bound(MP(-a, 0))!=S.end())
	{
		go(a);
		go(b);
		go(c);
		r++;
		//printf("%d %d %d\n", r, tmp, (int)S.size());
		res=min(res, r+max(((int)S.size()+1)/2, (int)S.size()-tmp));
	}
	printf("%d\n", res);
	return 0;
}