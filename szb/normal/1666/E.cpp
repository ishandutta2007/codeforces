#include<bits/stdc++.h>
using namespace std;
#define ll long long

#define For(i, x, y) for(ll i = (x); i <= (y); ++i)
#define FOr(i, x, y) for(ll i = (x); i >= (y); --i)
#define N 200050
ll m,n,a[N],ss1,ss2,L,R,mi1,mi2,Ans;
ll D[N], E[N], End[N];
int ch(int l, int r)
{
	//over_i :: E[i]..D[i]
	
	if(r<a[1] || l > a[2]) return 0;
	D[1] = min(r-a[1],a[2]-a[1]);
	E[1] = max(0ll,l-a[1]);
	for(int i=2;i<=n;++i) {
		int le = a[i] - a[i-1];
		if(D[i-1] + r < le)return 0;
		if(E[i-1] + l > a[i+1]-a[i-1])return 0;
		D[i] = min(D[i-1]+r-(a[i]-a[i-1]),a[i+1] - a[i]);
		E[i] = max(0ll,E[i-1]+l-(a[i]-a[i-1])); 
	}
	if(D[n] < m-a[n]) return 0;
	End[n] = m;
	for(int i=n-1; i; --i){
		if(End[i+1] - l <= a[i] + D[i]) End[i] = End[i+1]-l;
			else End[i] = a[i]+D[i];
	}
	
	return 1;
}

int Q(int p)
{
	int l = 1, r = p, ss=0;
	while(l<=r){
		int mi = l+r>>1;
		if(ch(mi,p)) ss = mi, l = mi+1; else r = mi-1;
	}
	return p-ss;
}	

int main(){
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;++i)scanf("%d",a+i);
	a[n+1]=m;
	if(n==1){
		printf("0 ");printf("%lld\n",m);
		return 0;
	}
	ll d = m/n, u = m/n+(m%n>0);
	ll l = 1, r = d;
	ll ansd =0;
	while (l <= r)
	{
		ll mid = l+r>>1;
		if(ch(mid, m)) ansd=mid, l=mid+1;
		else r = mid-1;
	}
	ll ansu = 0;
	l = u, r = m;
	while (l<=r)
	{
		ll mid = l+r>>1;
		if(ch(ansd, mid)) ansu = mid, r=mid-1;
		else l = mid+1;	
	}
//	cerr<<ansd<<' '<<ansu<<endl;
	ch(ansd, ansu);
	End[0] = 0;
	if(0)
	{
		For(i, 1, n) printf("%lld %lld\n", (i-1)*ansd, i*ansd);	
	}
	else 
	For(i, 1, n) 
	{
		printf("%lld %lld\n",End[i-1],End[i]);
	}
	
/*	L=1; R=m;
	while(R-L > 10){
		mi1 = L+(R-L)/3; mi2 = R-(R-L)/3;
		ss1 = Q(mi1); ss2 = Q(mi2);
		if(ss1 < ss2) R = mi2-1; else L=mi1+1; 
	}
	Ans = 2e9;
	for(int i=L;i<=R;++i)Ans=min(Ans,Q(i));
	for(int i=L;i<=R;++i)if(Q[i] == Ans){
		ch(i-Ans,i);
		
	}*/
}