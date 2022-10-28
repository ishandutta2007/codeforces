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
	int n;
	cin>>n;
	char c;
	int a[n],b[26]={0};
	for (int i = 0; i < n; ++i)
	{
		cin>>c;
		a[i]=c-'a';
		b[c-'a']++;
	}
	int q,x,y;
	cin>>q;
	for (int i = 0; i < q; ++i)
	{
		cin>>x>>c;
		if (x+b[c-'a']>=n)
		{
			cout<<n<<endl;
			continue;
		}
		else{
			y=c-'a';
			int count=0,ans=0,indx=0;
			for (int i = 0; i < n; ++i)
			{
				if (a[i]!=y)
				{
					count++;
				}
				if (count>x)
				{
					while(a[indx]==y){
						indx++;
					}
					indx++;
					count--;
				}
				if (i-indx+1>ans)
				{
					ans=i-indx+1;
				}
			}
			cout<<ans<<endl;
		}
	}

	return 0;
}