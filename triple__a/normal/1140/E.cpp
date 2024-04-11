#include<bits/stdc++.h>
using namespace std;

const int mod=998244353;
const int maxn=200007;

long long ans=1,t=1;
int n,m;
vector<int> vec;
int a[maxn],dp[maxn][2];

int mult(int a,int b){
	return 1LL*a*b%mod;
}
int calc(vector<int> vec){
	int i=0,n=vec.size(),l=i;
	long long t=1;
	while (i<n){
		if (i+1<n&&vec[i]>0&&vec[i]==vec[i+1]) return 0;
		l=i;
		while (i<n&&vec[i]==-1) i++;
		if (l==i){
			i++;
			continue;
		}
		if (l==0){
			dp[1][0]=1;
			for (int j=1;j<i-l;++j){
				dp[j+1][0]=(1LL*(m-1)*dp[j][0])%mod;
			}
			if (i<n){
				t=mult(t,mult(dp[i-l][0],m-1));
			}
			if (i==n){
				t=mult(t,mult(dp[i-l][0],m));
			}
		}
		else{
			dp[1][0]=1,dp[1][1]=0;
			for (int j=1;j<i-l;++j){
				dp[j+1][0]=(1LL*(m-2)*dp[j][0]+dp[j][1])%mod;
				dp[j+1][1]=(1LL*(m-1)*dp[j][0])%mod;
			}
			if (i<n){
				if (vec[i]==vec[l-1]){
					t=mult(t,mult(m-1,dp[i-l][0]));
				}
				else{
					t=mult(t,(mult(m-2,dp[i-l][0])+dp[i-l][1])%mod);
				}
			}
			else{
				t=mult(t,(mult(m-1,dp[i-l][0])+dp[i-l][1])%mod);
			}
		}
//		if (l==i) i++;
	}
	cout<<endl;
	return t;
}

int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	vec.clear();
	for (int i=1;i<=n;i+=2){
		vec.push_back(a[i]);
	}
	t=calc(vec);
	ans=mult(ans,t);
//	printf("%d\n",ans);
	vec.clear();
	for (int i=2;i<=n;i+=2){
		vec.push_back(a[i]);
	}
	t=calc(vec);
	ans=mult(ans,t);
	printf("%d\n",ans);
	return 0;
}