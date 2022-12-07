#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
#define pll pair<ll,ll> 
#define y1 orzkcz
using namespace std;

const int mo=1000000007;
int n,k,ans;
int f[1005];
void solve(){
	scanf("%d%d",&n,&k);
	memset(f,0,sizeof(f));
	f[1]=1; ans=(k!=1);
	for (int i=1;i<=k-1;i++){
		for (int j=1;j<=n;j++) ans=(ans+f[j])%mo;
		if (i&1){
			int s=0;
			for (int j=1;j<=n;j++){
				int ss=s;
				s=(s+f[j])%mo;
				f[j]=ss;
			}
		}
		else{
			int s=0;
			for (int j=n;j>=1;j--){
				int ss=s;
				s=(s+f[j])%mo;
				f[j]=ss;
			}
		}
	}
	for (int i=1;i<=n;i++)
		ans=(ans+f[i])%mo; 
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve(); 
}