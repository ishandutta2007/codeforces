#include <bits/stdc++.h>
using namespace std;
 


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
#define PI 3.14159265359
#define EULER 2.7182818284
#define MOD 1000000007

int main(){
	int n,m;
	cin>>n>>m;
	if (m!=1)
	{
		cout<<"Yes";
		return 0;
	}
	else{
		int a[n];
		FOR(i,n){
			cin>>a[i];
		}
		int x;
		cin>>x;
		if (a[0]==0)
		{
			a[0]=x;
		}
		for (int i = 1; i < n; ++i)
		{
			if (a[i]==0)
			{
				a[i]=x;
			}
			if (a[i]<a[i-1])
			{
				cout<<"Yes";
				return 0;
			}
		}
		cout<<"No";
	}
	return 0;
}