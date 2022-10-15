#include<bits/stdc++.h>
using namespace std;

const int maxn=1000007;
int phi[maxn],p[maxn],n,k,cnt;
bool vis[maxn];

void gen_phi(){
	for (int i=2;i<=n;++i){
		if (!phi[i]){
			for (int j=i;j<=n;j+=i){
				if (!phi[j]) phi[j]=j;
				phi[j]=phi[j]/i*(i-1);
			}
		}
	}
}

int main(){
	cin>>n>>k;
	if (k==1){
		cout<<3<<endl;
		return 0;
	}
	gen_phi();
	sort(phi+2,phi+n+1);
	long long ans=1;
	for (int i=2;i<=k+2;++i){
		ans+=phi[i];
	}
	cout<<ans<<endl;
	return 0;
}