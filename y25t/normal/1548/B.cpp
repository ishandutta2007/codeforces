#include<bits/stdc++.h>
#define ll long long
#define N 200005

ll gcd(ll x,ll y){
	return y?gcd(y,x%y):x;
}

int T;

int n;
ll a[N];

#define W 20
ll f[N][W];

int ans;

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		for(int i=1;i<n;i++)
			f[i][0]=a[i]>a[i+1]?a[i]-a[i+1]:a[i+1]-a[i];
		for(int j=1;j<W;j++)
			for(int i=1;i<n-(1<<j)+1;i++)
				f[i][j]=gcd(f[i][j-1],f[i+(1<<(j-1))][j-1]);
		ans=0;
		for(int i=1;i<n;i++){
			int x=i;
			ll tmp=0;
			for(int j=W-1;~j;j--)
				if(x+(1<<j)-1<n&&gcd(tmp,f[x][j])!=1){
					tmp=gcd(tmp,f[x][j]);
					x+=1<<j;
				}
			ans=std::max(ans,x-i);
		}
		printf("%d\n",ans+1);
	}
}