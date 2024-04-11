#include<bits/stdc++.h>

using namespace std;

const int maxn=3007;
const int mod=1e9+7;

int n,s[maxn],ans[maxn];
long long dp[maxn][maxn];

vector<int> get_pi(int s[],int n){
	int j=-1;
	vector<int> pi;
	pi.clear();
	pi.push_back(-1);
	for (int i=1;i<=n;++i){
		while (j>-1&&s[i]!=s[j+1]){
			j=pi[j];
		}
		pi.push_back(++j);
	}
	return pi;
}

bool ck(int j){
	int t=s[j]+s[j-1]*10+s[j-2]*100+s[j-3]*1000;
	if (t==11||t==101||t==1110||t==1111) return 0;
	return 1;
}

bool kmp(int m,int k){
//	cout<<m<<" "<<k<<endl;
	int tmp[maxn<<2];
	for (int i=1;i<m;++i){
		tmp[k+1+i]=s[i];
	}
	tmp[k+1]=2;
	for (int i=1;i<=k;++i){
		tmp[i]=s[m-k+i];
	}
/*	for (int i=1;i<=m+k;++i){
		cout<<tmp[i]<<" ";
	}
	cout<<endl;*/
	vector<int> pi=get_pi(tmp,m+k);
	for (int i=1;i<=m+k;++i){
		if (pi[i]==k) return 1;
	}
	return 0;
}

int get_dp(int i,int j){
	if (i>j) return 1;
	long long ans=dp[i][j-1];
	if (j>=i+1) ans=(ans+dp[i][j-2])%mod;
	if (j>=i+2) ans=(ans+dp[i][j-3])%mod;
	if (j>=i+3){
//		ans=(ans+7*dp[i][j-4])%mod;
		if (ck(j)){
			ans=(ans+dp[i][j-4])%mod;
		}
	} 
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for (int i=1;i<=n;++i){
		cin>>s[i];
	}
	for (int i=1;i<=n;++i){
		int l=0,r=i-1,md;
		while (l<r){
			md=(l+r)>>1;
			if (kmp(i,md+1)){
				l=md+1;
			}
			else{
				r=md;
			}
		}
//		cout<<l<<endl;
		ans[i]=l;
	}
	for (int i=0;i<=n;++i){
		for (int j=1;j<=i+1;++j){
			dp[j][i]=get_dp(j,i);
		}
	}
	int ret=0;
	for (int i=1;i<=n;++i){
		for (int j=1;j<=i-ans[i];++j){
			ret=(ret+dp[j][i])%mod;
		}
		cout<<ret<<endl;
	}
	return 0;
}