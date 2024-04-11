#include <bits/stdc++.h>
using namespace std;
 
double dist(int x1,int y1,int x2,int y2){
	long long int z=1LL*(x1-x2)*(x1-x2)+1LL*(y1-y2)*(y1-y2);
	double a = sqrt(1.00*z);
	return a;
}

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define si(n) scanf("%d",&n)
#define iout(n) printf("%d\n",n)
#define slli(n) scanf("%lld",&n)
#define lliout(n) printf("%lld\n",n)
#define FOR(i,n) for(int i=0;i<n;i++)

#define EPS 10e-9;
#define PI 3.141592653589793238462643383
#define EULER 2.7182818284
#define MOD 1000000007

int main(){
	int n;
	cin>>n;
	int x[n],y[n],r[n],z[n]={0};
	double ar[n];
	FOR(j,n){
		cin>>x[j]>>y[j]>>r[j];
		ar[j]=PI*1.00*r[j]*r[j];
		for (int i = j-1; i >=0; --i)
		{
			double d=dist(x[j],y[j],x[i],y[i]);
			if (r[j]>r[i]&&(d<r[j]))
			{
				z[i]++;
			}
			else if (r[i]>r[j]&&d<r[i])
			{
				z[j]++;
			}
		}
	}
	double ans=0;
	FOR(i,n){
		if (z[i]==0)
		{
			ans+=ar[i];
		}
		else if (z[i]%2==1)
		{
			ans+=ar[i];
		}
		else{
			ans-=ar[i];
		}
	}
	cout<<setprecision(18)<<ans<<endl;
	return 0;
}