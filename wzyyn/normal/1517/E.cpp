#include<bits/stdc++.h>
using namespace std;

const int N=200005;

int n,a[N];
long long r[N],qa[N],qb[N];
long long ans,s;


void solve(int fir,int las){
	int ta=0,tb=0;
	long long lim=s;
	if (fir) lim-=a[1];
	if (las) lim-=a[n];
	r[0]=r[1]=0;
	for (int i=2;i<n;i++) r[i]=r[i-2]+a[i];
	for (int i=0;i<n;i+=2)
		if ((fir==1||i!=0)&&(las==0||i!=n-1)) qa[++ta]=r[i];
	for (int i=1;i<n;i+=2)
		if ((fir==1||i!=0)&&(las==0||i!=n-1)) qb[++tb]=r[i];
	for (int i=1,j=tb;i<=ta;i++){
		for (;j&&qa[i]+qb[j]>lim;--j);
		ans+=j;
	}
}
void solve(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	if (n==1){
		puts("1");
		return;
	}
	s=0;
	for (int i=1;i<=n;i++) s+=a[i];
	s=(s-1)/2;
	
	ans=0;
	for (int i=0;i<2;i++)
		for (int j=0;j<2;j++)
			solve(i,j);
	long long t=0;
	for (int i=n;i>=1;i--){
		ans+=(t<=s);
		t+=a[i];
	}
	cout<<ans%998244353<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}