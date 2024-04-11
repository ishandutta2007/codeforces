#include <bits/stdc++.h>
#define INL inline
#define REG register
#define DB double
#define LDB long double
#define ULL unsigned long long
#define LL long long

#define RPT(i,x,y) for (REG int i=(x);i<(y);i++)
#define DRPT(i,x,y) for (REG int i=(x);i>(y);i--)
#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 310000
#define MAXM 10000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

typedef pair<int,int> pii;
int n;
pii a[MAXN];
LL fac[MAXN];

LL num1=1,num2=1,num3=1;
bool cmp1(pii p1,pii p2)
{
	return p1.first<p2.first || p1.first==p2.first && p1.second<p2.second;
}

bool cmp2(pii p1,pii p2)
{
	return p1.second<p2.second;
}

int main()
{
	cin>>n;
	fac[0]=fac[1]=1;
	RPT(i,2,n+1)
		fac[i]=i*fac[i-1]%MOD;
	RPT(i,0,n)
		scanf("%d%d",&a[i].first,&a[i].second);
	sort(a,a+n,cmp1);
	int pos=0;
	int lst;
	int cnt=1;
	bool f=false;
	while (pos<n)
	{
		//WRT(pos);
		lst=pos;
		while (a[pos+1].first==a[pos].first && pos+1<n)
		{
			if (a[pos+1].second!=a[pos].second)
			{
				//WRT(cnt);
				num2=num2*fac[cnt]%MOD;
				cnt=1;
			}
			else
				cnt++;
			pos++;
		}
		num2=num2*fac[cnt]%MOD;
		cnt=1;
		if (pos!=n-1 && a[pos].second>a[pos+1].second)
			f=true;
		pos++;
		num1=num1*fac[pos-lst]%MOD;
	}
	if (f)
		num2=0;
	sort(a,a+n,cmp2);
	pos=0;
	while (pos<n)
	{
		lst=pos;
		while (a[pos+1].second==a[pos].second && pos+1<n)
			pos++;
		pos++;
		num3=num3*fac[pos-lst]%MOD;
	}
	cout<<((fac[n]-num1-num3+num2)%MOD+MOD)%MOD;
	return ~~(0^_^0);
}