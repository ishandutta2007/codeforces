#include<bits/stdc++.h>
#define ll long long
#define N 10005

int n;
ll a[N];

int l[N],r[N];
inline ll sol(ll x=0,int L=1,int R=n){
	for(int i=L;i<=R;i++)
		l[i]=i-1,r[i]=i+1;
	for(int i=L;i<=R;i++)
		while(l[i]>=L&&a[l[i]]>=a[i])
			l[i]=l[l[i]];
	for(int i=R;i>=L;i--)
		while(r[i]<=R&&a[r[i]]>=a[i])
			r[i]=r[r[i]];
	for(int i=L;i<=R;i++)
		l[i]++,r[i]--;
	ll res=0;
	for(int i=L;i<=R;i++)
		res=std::max(res,(a[i]-x)*(r[i]-l[i]+1));
	return res;
}

ll mn[N];
inline ll cal(ll x,int L,int R){
	ll res=0;
	for(int o=0;o<2;o++){
		mn[R]=x;
		for(int i=R+1;i<=n;i++)
			mn[i]=std::min(mn[i-1],a[i]);
		ll t=x,s=0;
		for(int i=L-1,j=n;i;i--){
			t=std::min(t,a[i]);
			while(mn[j]<x-t)
				s=std::max(s,mn[j]*(j-L+1)),j--;
			res=std::max(res,t*(R-i+1)+std::max((x-t)*(j-L+1),s));
		}
		std::reverse(a+1,a+n+1),L=n-L+1,R=n-R+1,std::swap(L,R);
	}
	return res;
}

int L[N],R[N];

ll ans;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	ans=sol();
	for(int i=1;i<=n;i++)
		L[i]=l[i],R[i]=r[i];
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(R[i]<=L[j])
				ans=std::max(ans,a[i]*(R[i]-L[i]+1)+a[j]*(R[j]-L[j]+1));
	for(int i=1;i<=n;i++){
		ans=std::max(ans,a[i]*(R[i]-L[i]+1)+sol(a[i],L[i],R[i]));
		ans=std::max(ans,cal(a[i],L[i],R[i]));
	}
	printf("%lld\n",ans);
}