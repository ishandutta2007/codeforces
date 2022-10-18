#include<bits/stdc++.h>
#define ll long long
#define N 1000005

int T;

int n,m,a[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		int k=0;
		for(int i=1;i<=m;i++){
			int x;
			scanf("%d",&x);
			k=std::__gcd(k,x);
		}
		ll a0=0,a1=0;
		for(int i=0;i<k;i++){
			std::vector<int> V;
			ll s=0;
			for(int j=i?0:1;j*k+i<=n;j++)
				V.push_back(a[j*k+i]),s+=a[j*k+i];
			std::sort(V.begin(),V.end());
			ll t0=s,t1=-0x3f3f3f3f3f3f3f3fll;
			for(int j=0;j<(int)V.size();j++){
				s-=2*V[j];
				if(j&1)
					t0=std::max(t0,s);
				else
					t1=std::max(t1,s);
			}
			a0+=t0,a1+=t1;
		}
		printf("%lld\n",std::max(a0,a1));
	}
}