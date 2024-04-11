#include<bits/stdc++.h>
#define ll long long
#define N 105

int T;

int n,a[N],b[N];

std::bitset<N*N> f;

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		int s=0;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),s+=a[i];
		for(int i=1;i<=n;i++)
			scanf("%d",&b[i]),s+=b[i];
		f.reset();
		f[0]=1;
		for(int i=1;i<=n;i++)
			f=(f<<a[i])|(f<<b[i]);
		ll res=0x3f3f3f3f3f3f3f3f;
		for(int i=1;i<=s/2;i++)
			if(f[i])
				res=std::min(res,1ll*i*i+1ll*(s-i)*(s-i));
		for(int i=1;i<=n;i++)
			res+=1ll*(n-2)*a[i]*a[i];
		for(int i=1;i<=n;i++)
			res+=1ll*(n-2)*b[i]*b[i];
		printf("%lld\n",res);
	}
}