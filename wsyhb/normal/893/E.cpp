#include<bits/stdc++.h>
using namespace std;
const int P=1e9+7;
inline void add(int &a,int b)
{
	a=a+b-(a+b>=P?P:0);
}
inline void mul(int &a,int b)
{
	a=1ll*a*b%P;
}
inline int get_sum(int a,int b)
{
	return a+b-(a+b>=P?P:0);
}
inline int get_product(int a,int b)
{
	return 1ll*a*b%P;
}
const int range=2e6;
const int max_range=range+5;
int fac[max_range],inv[max_range],inv_fac[max_range],power[max_range];
void init()
{
	fac[0]=inv_fac[0]=power[0]=1;
	fac[1]=inv[1]=inv_fac[1]=1;
	power[1]=2;
	for(int i=2;i<=range;++i)
	{
		fac[i]=get_product(fac[i-1],i);
		inv[i]=get_product(P-P/i,inv[P%i]);
		inv_fac[i]=get_product(inv_fac[i-1],inv[i]);
		power[i]=get_sum(power[i-1],power[i-1]);
	}
}
inline int C(int n,int m)
{
	if(n<0||m<0||n<m)
		return 0;
	return get_product(fac[n],get_product(inv_fac[m],inv_fac[n-m]));
}
int main()
{
	init();
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		int ans=1;
		for(int i=2;i*i<=x;++i)
		{
			if(x%i==0)
			{
				int cnt=0;
				while(x%i==0)
					x/=i,++cnt;
				mul(ans,C(cnt+y-1,y-1));
			}
		}
		if(x>1)
			mul(ans,y);
		mul(ans,power[y-1]);
		printf("%d\n",ans);
	}
	return 0;
}