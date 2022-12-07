#include<bits/stdc++.h>

using namespace std;

const int N=1000005;
int fl[N];
int a[N],b[N];
int n,k,sum[N];
void init(){
	for (int i=2;i<N;i++) if (!fl[i])
		for (int j=i+i;j<N;j+=i)
			fl[j]=1;
}
void solve(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if (a[i]==1) b[i]=0;
		else b[i]=(fl[a[i]]?2:1);
	}
	long long ans=0;
	for (int i=1;i<=k;i++){
		int s=0;
		for (int j=i;j<=n;j+=k){
			++sum[s];
			s+=b[j];
			if (b[j]==1) --ans;
			if (s) ans+=sum[s-1];
		}
		s=0;
		for (int j=i;j<=n;j+=k){
			--sum[s];
			s+=b[j];
		}
	}
	cout<<ans<<endl;
}
int main(){
	init();
	int T;
	scanf("%d",&T);
	while (T--) solve();
}