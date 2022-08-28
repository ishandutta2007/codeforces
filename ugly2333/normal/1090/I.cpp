//CF1090I
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 1e7+17;
const LL inf = (LL)1<<32;
LL f[N];
int main()
{
	int tc,i;
	LL n,l,r,x,y,z,a,b,c,o,e,ans;
	cin>>tc;
	while(tc--){
		cin>>n>>l>>r>>x>>y>>z>>b>>c;
		f[1]=b%(r-l+1)+l,f[2]=c%(r-l+1)+l;
		for(i=3;i<=n;i=i+1){
			a=(b*x%inf+c*y%inf+z+inf*10)%inf;
			f[i]=a%(r-l+1)+l;
			b=c,c=a;
		}
		//cin>>n;
		ans=0;
		o=0;
		for(i=1;i<=n;i=i+1){
			//cin>>f[i];
			if(f[i]<0)
				o=min(o,f[i]);
			if(f[i]>0)
				ans=min(ans,o*f[i]);
		}
		if(ans<0){
			cout<<ans<<endl;
			continue;
		}
		ans=1;
		o=0;
		e=0;
		for(i=1;i<=n;i=i+1){
			if(!f[i]){
				if(e)
					ans=0;
				o=1;
			}
			if(f[i]<0)
				e=1;
			if(f[i]>0)
				if(o)
					ans=0;
		}
		if(!ans){
			cout<<0<<endl;
			continue;
		}
		ans=(LL)3<<61;
		o=inf;
		for(i=1;i<=n;i=i+1){
			if(f[i]>0){
				if(o<f[i])
					ans=min(ans,o*f[i]);
				else
					o=f[i];
			}
		}
		o=-inf;
		for(i=n;i;i=i-1){
			if(f[i]<0){
				if(o>f[i])
					ans=min(ans,o*f[i]);
				else
					o=f[i];
			}
		}
		if(ans>=(LL)3<<61)
			cout<<"IMPOSSIBLE\n";
		else
			cout<<ans<<endl;
	}
	return 0;
}