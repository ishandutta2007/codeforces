#include<bits/stdc++.h> 
#define int long long
using namespace std;
int n,a[2000000],b[2000000],h[2000000],f[2000000],lsg,ans,l,r,kk;
int hash(int k){
	int d=k%lsg;if (d<0)d=-d;while (h[d]!=k&&f[d]!=0)d=d==lsg?1:d+1;
	h[d]=k;return d; 
} 
signed main(){
	ios::sync_with_stdio(false);
	cin>>n;lsg=1e6+7;
	for (int i=1;i<=n;i++)cin>>a[i],b[i]=b[i-1]+max(a[i],0ll);
	ans=-5e18;for (int i=1;i<=n;i++){
		int k=hash(a[i]);if (f[k]){
			if (b[i-1]-b[f[k]]+a[f[k]]+a[i]>ans)ans=b[i-1]-b[f[k]]+a[f[k]]+a[i],l=f[k],r=i;
		}else f[k]=i;
	}for (int i=1;i<=n;i++)if (a[i]<0&&l!=i&&r!=i||i<l||i>r)kk++;
	cout<<ans<<' '<<kk<<endl;for (int i=1;i<=n;i++)if (a[i]<0&&l!=i&&r!=i||i<l||i>r)cout<<i<<' ';cout<<endl;
}