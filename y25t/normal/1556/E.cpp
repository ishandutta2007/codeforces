#include<bits/stdc++.h>
#define ll long long
#define N 100005
#define W 19

int n,q,a[N];

ll s[N],mn[N][W],mx[N][W];

int lg[N];
inline ll qmn(int l,int r){
	int k=lg[r-l+1];
	return std::min(mn[l][k],mn[r-(1<<k)+1][k]);
}
inline ll qmx(int l,int r){
	int k=lg[r-l+1];
	return std::max(mx[l][k],mx[r-(1<<k)+1][k]);
}

int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		a[i]=x-a[i];
		mn[i][0]=mx[i][0]=s[i]=s[i-1]+a[i];
	}
	lg[0]=-1;
	for(int i=1;i<=n;i++)
		lg[i]=lg[i>>1]+1;
	for(int j=1;j<W;j++)
		for(int i=1;i+(1<<j)-1<=n;i++){
			mn[i][j]=std::min(mn[i][j-1],mn[i+(1<<(j-1))][j-1]);
			mx[i][j]=std::max(mx[i][j-1],mx[i+(1<<(j-1))][j-1]);
		}
	while(q--){
		int l,r;
		scanf("%d%d",&l,&r);
		ll mx_=qmx(l,r)-s[l-1],mn_=qmn(l,r)-s[l-1];
		if(mn_<0||s[r]!=s[l-1])
			puts("-1");
		else
			printf("%lld\n",mx_);
	}
}