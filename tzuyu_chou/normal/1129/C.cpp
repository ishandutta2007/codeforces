#include<iostream>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
int n;
int a[3001];
ll dp[3001][3001];
int maxi[3001];
int f[3001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n;for(int i=1; i<=n ;i++) cin >> a[i];
	for(int i=1; i<=n ;i++){
		maxi[i]=i;
		dp[i][i-1]=1;
		for(int j=i; j<=n ;j++){
			for(int k=max(0,j-4); k<=j-1 ;k++){
				if(k==j-4){
					if(a[j-3]==0 && a[j-2]==0 && a[j-1]==1 && a[j]==1) continue;
					if(a[j-3]==0 && a[j-2]==1 && a[j-1]==0 && a[j]==1) continue;
					if(a[j-3]==1 && a[j-2]==1 && a[j-1]==1 && a[j]==0) continue;
					if(a[j-3]==1 && a[j-2]==1 && a[j-1]==1 && a[j]==1) continue;
				}
				dp[i][j]+=dp[i][k];
				if(dp[i][j]>=mod) dp[i][j]-=mod;
				
			}
			//cout << dp[i][j] << ' ';
		}
		//cout << endl;
	}
	for(int i=1; i<=n ;i++){
		f[i-1]=i-2;f[i]=i-1;
		for(int j=i+1; j<=n ;j++){
			f[j]=f[j-1];
			while(f[j]>=i-1 && a[f[j]+1]!=a[j]) f[j]=f[f[j]];
			f[j]++;
			maxi[j]=min(maxi[j],j-f[j]+i-1);
		}
	}
	int ans=0;
	for(int j=1; j<=n ;j++){
		for(int i=1; i<=j ;i++){
			if(maxi[j]<i) continue;
			ans+=dp[i][j];
			if(ans>=mod) ans-=mod;
		}
		cout << ans << '\n';
	}
}