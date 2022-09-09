#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ldb long double
const ldb inf=9e18;
const int N=150050;
ll p[N],x[N],mn[N],mx[N];
int id[N];
bool comp1(int i, int j){ return p[i]*x[j]>p[j]*x[i];}
bool comp2(int i, int j){ return p[i]>p[j];}
int main()
{
	int n,i,j,k;
	ll T=0;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%lld",&p[i]);
	for(i=1;i<=n;i++) scanf("%lld",&x[i]),id[i]=i,T+=x[i];
	sort(id+1,id+1+n,comp1);
	ll sum=0;
	for(i=1;i<=n;i=j)
	{
		for(j=i;j<=n && p[id[i]]*x[id[j]]==p[id[j]]*x[id[i]];j++) mx[id[j]]=sum+x[id[j]];
		for(k=i;k<j;k++) sum+=x[id[k]];
		for(k=i;k<j;k++) mn[id[k]]=sum;
	}
	sort(id+1,id+1+n,comp2);
	ldb bot=0,top=1,c=0,mid;
	cout<<fixed<<setprecision(12);
	for(int work=0;work<30;work++)
	{
		mid=(top+bot)/2;
		ldb cur=inf;
		bool ok=1;
		for(j=1;j<=n;j=k)
		{
			for(k=j;k<=n && p[id[k]]==p[id[j]];k++)
			{
				i=id[k];
				ldb mxp=p[i]-(ldb)p[i]*mx[i]*mid/T;
				if(mxp>cur) ok=0;
			}
			for(k=j;k<=n && p[id[k]]==p[id[j]];k++)
			{
				i=id[k];
				ldb mnp=p[i]-(ldb)p[i]*mn[i]*mid/T;
				cur=min(cur,mnp);
			}
		}
		if(!ok) top=mid;
		else bot=mid;
	}
	cout<<(top+bot)/2<<"\n";
	return 0;
}