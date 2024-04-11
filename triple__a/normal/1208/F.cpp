#include<bits/stdc++.h>
using namespace std;
 
const int maxn=2000007;
 
int dp[maxn][23],a[maxn],n;

void update(int val,int b=20){
	if (dp[val][b]>1||b==-1) return;
	dp[val][b]++;
	update(val,b-1);
	if (val>>b&1) update(val^(1<<b),b);
}
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for (int i=1;i<=n;++i){
		cin>>a[i];
	}
//	cout<<"hi"<<endl;
	int ans=0;
	for (int i=n;i>0;--i){
		int val=0;
		for (int j=20;j>-1;--j){
			if (a[i]>>j&1) continue;
			int tmp=val|(1<<j); 
			if (dp[tmp][0]>1){
				val=tmp;
			}
		}
		update(a[i]);
		if (i<n-1) ans=max(val|a[i],ans);
	}
	cout<<ans<<endl;
	return 0;
}