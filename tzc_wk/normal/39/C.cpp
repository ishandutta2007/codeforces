#include <bits/stdc++.h>
using namespace std;
struct node{
	int l,r;
} a[2005];
int dp[4005][4005],id[4005][4005],from[4005][4005],b[4005];
vector<int> g[4005],ans;
int n,cnt;
inline void print(int l,int r){
	if(l>r)			return;
	if(id[l][r])	ans.push_back(id[l][r]);
	if(from[l][r])	print(l,from[l][r]),print(from[l][r],r);
	else			print(l+1,r);
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int c,r;cin>>c>>r;
		a[i].l=c-r;a[i].r=c+r;
//		cout<<a[i].l<<" "<<a[i].r<<endl;
		b[++cnt]=a[i].l;b[++cnt]=a[i].r;
	}
	sort(b+1,b+cnt+1);
	cnt=unique(b+1,b+cnt+1)-b-1;
	for(int i=1;i<=n;i++){
		a[i].l=lower_bound(b+1,b+cnt+1,a[i].l)-b;
		a[i].r=lower_bound(b+1,b+cnt+1,a[i].r)-b;
//		cout<<a[i].l<<" "<<a[i].r<<endl;
	}
	for(int i=1;i<=n;i++){
		g[a[i].l].push_back(a[i].r);
		id[a[i].l][a[i].r]=i;
	}
	for(int len=1;len<=cnt;len++){
		for(int l=1,r=len;r<=cnt;l++,r++){
			dp[l][r]=dp[l+1][r];
			for(int i=0;i<g[l].size();i++){
				int x=g[l][i];
				if(x<r&&dp[l][x]+dp[x][r]>dp[l][r]){
					dp[l][r]=dp[l][x]+dp[x][r];
					from[l][r]=x;
				}
			}
			dp[l][r]+=(id[l][r])?1:0;
//			cout<<l<<" "<<r<<" "<<dp[l][r]<<endl;
		}
	}
	cout<<dp[1][cnt]<<endl;
	print(1,cnt);
	sort(ans.begin(),ans.end());
	for(int i=0;i<ans.size();i++)	cout<<ans[i]<<" ";
}