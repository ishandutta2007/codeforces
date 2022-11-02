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

int n, T[200002];
LL P[200002];
double r;
PII x=MP(1, 1), y=MP(0, -1);

void solve(int me, int ind, int val, int p1, int l)
{
	//printf("%d %d %d %d %d\n", me, ind, val, p1, l);
	if(l<=0)
		return;
	int k1=p1-l+1, mid1=(p1+k1)/2;
	while(k1<=p1)
	{
		int mid2=n-(ind-1-mid1);
		LL sum=val+P[ind-1]-P[mid1-1]+P[n]-P[mid2-1];
		int num=me+ind-mid1+1+n-mid2;
		double rr=(double)sum/(double)num;
		//if(me==1 && ind==2)
		//	printf("  %lld %d %d %d %lf\n", sum, num, mid1, mid2, rr-(double)val);
		if(me==1 && rr-(double)val>r)
		{
			r=rr-(double)val;
			x=MP(mid1, ind);
			y=MP(mid2, n);
		}
		if(me==2 && rr-((double)val)/2>r)
		{
			r=rr-((double)val)/2;
			x=MP(mid1, ind+1);
			y=MP(mid2, n);
		}
		LL sum2=sum+T[mid1-1]+T[mid2-1];
		if(mid2>ind+me && mid1>1 && sum*(LL)(num+2)<sum2*(LL)num)
			p1=mid1-1;
		else
			k1=mid1+1;
		mid1=(p1+k1)/2;
	}
}

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
		scanf("%d", T+i);
	sort(T+1, T+n+1);
	for(int i=1; i<=n; i++)
		P[i]=P[i-1]+T[i];
	for(int i=1; i<=n; i++)
	{
		solve(1, i, T[i], i-1, min(i-1, n-i));
		if(i<n)
			solve(2, i, T[i]+T[i+1], i-1, min(i-1, n-i-1));
	}
	printf("%d\n", x.S-x.F+y.S-y.F+2);
	for(int i=x.F; i<=x.S; i++)
		printf("%d ", T[i]);
	for(int i=y.F; i<=y.S; i++)
		printf("%d ", T[i]);
	printf("\n");
	return 0;
}