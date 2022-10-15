#include<bits/stdc++.h>
using namespace std;

const int maxn=300007;

int n,dp[maxn],mn,idx,ans1=0,l1=1,r1=1,ans2=0,l2=1,r2=1;
string s;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>s;
	mn=0,idx=0;
	for (int i=1;i<=n;++i){
		if (s[i-1]=='('){
			dp[i]=dp[i-1]+1;
		}
		else{
			dp[i]=dp[i-1]-1;
		}
		if (mn>dp[i]){
			mn=dp[i],idx=i;
		}
	}
	if (dp[n]){
		printf("0\n1 1");
		return 0;
	}
	int cnt=0,tl=0;
	for (int i=0;i<n;++i){
		if (dp[(i+idx)%n]==mn){
			if (cnt>ans1){
				ans1=cnt,l1=tl,r1=i;
			}
			cnt=0,tl=i;
		}
		if (dp[(i+idx)%n]==mn+1){
			cnt++;
		}
	}
	if (cnt>ans1){
		ans1=cnt,l1=tl,r1=n;
	}
	cnt=0,tl=0;
	for (int i=0;i<n;++i){
		if (dp[(i+idx)%n]<=mn+1){
			if (cnt>ans2){
				ans2=cnt,l2=tl,r2=i;
			}
			cnt=0,tl=i;
		} 
		if (dp[(i+idx)%n]==mn+2){
			cnt++;
		}
	}
	if (cnt>ans2){
		ans2=cnt,l2=tl,r2=n;
	}
	for (int i=0;i<n;++i){
		if (dp[i]==mn){
			ans2++;
		}
	}
//	printf("%d %d %d %d\n",l1,r1,l2,r2);
	int u=0;
	for (int i=0;i<n;++i){
		if (dp[i]==mn) ++u;
	}
	if (u==n/2){
		printf("%d\n%d %d",u,1,1);
		return 0; 
	}
	if (ans1>ans2){
		printf("%d\n%d %d",ans1,(l1+idx)%n+1,(r1+idx-1)%n+1);
	}
	else{
		printf("%d\n%d %d",ans2,(l2+idx)%n+1,(r2+idx-1)%n+1);
	}
	return 0;
}