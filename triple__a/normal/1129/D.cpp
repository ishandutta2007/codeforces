#include<bits/stdc++.h>
using namespace std;

const int mod=998244353;
const int maxn=200007;
const int maxm=1007;
int n,k,bs,a[maxn],b[maxn],dp[maxn],t[maxn],rec[maxm][maxm<<2];
vector<int> s[maxn];

void update(int u,int w){
	b[u]+=w;
	int bn=(u-1)/bs,L=bn*bs+1,R=(bn+1)*bs;
	t[bn]+=w;
	if (w<0){
		int sum=0;
		for (int i=R;i>u;--i){
			sum+=b[i];
		}
		for (int i=u;i>=L;--i){
			sum+=b[i];
			rec[bn][sum+maxm]=(rec[bn][sum+maxm]+dp[i-1])%mod;
			rec[bn][sum+maxm+1]=(rec[bn][sum+maxm+1]+dp[i-1])%mod;
		}
	}
	else{
		int sum=0;
		for (int i=R;i>u;--i){
			sum+=b[i];
		}
		for (int i=u;i>=L;--i){
			sum+=b[i];
			rec[bn][sum-1+maxm]=((rec[bn][sum-1+maxm]-dp[i-1])%mod+mod)%mod;
		}
	}
}


int query(int u){
	int bn=(u-1)/bs,L=bn*bs+1,R=(bn+1)*bs,ans=0,sum=0;
	for (int i=bn;i>-1;--i){
		if (sum-k<=bs)
		ans=(ans+rec[i][min(maxm+k-sum,maxm+bs)])%mod;
		sum+=t[i];
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin>>n>>k;
	bs=sqrt(n);
	for (int i=1;i<=n;++i){
		cin>>a[i];
	}
	dp[0]=1;
	for (int i=1;i<=n;++i){
		int bn=(i-1)/bs;
		for (int j=0;j<=bs;++j){
			rec[bn][j+maxm]=(rec[bn][j+maxm]+dp[i-1])%mod;
		}
		update(i,1);
		int ts=s[a[i]].size();
		if (ts>=1){
			update(s[a[i]][ts-1],-2);
			if (ts>=2){
				update(s[a[i]][ts-2],1);
			}
		}
		for (int j=0;j<n;++j){
//			cout<<rec[j][maxm-1]<<" "<<rec[j][maxm]<<" "<<rec[j][maxm+1]<<endl;
		}
//		cout<<endl;
		s[a[i]].push_back(i);
		dp[i]=query(i);
	}
	cout<<dp[n]<<endl;
	return 0;
}