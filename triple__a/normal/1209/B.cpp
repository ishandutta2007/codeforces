#include<bits/stdc++.h>
using namespace std;
 
const int maxn=500007;
const int u=500000;
int n;
string s;
int a[maxn],b[maxn];
int ans=0;
bool vis[maxn];
 
int main(){
	memset(vis,0,sizeof(vis));
	cin>>n;
	cin>>s;
	for (int i=1;i<=n;++i){
		cin>>a[i]>>b[i];
	}
	for (int i=0;i<n;++i){
		vis[i+1]=(s[i]=='1');
	}
	ans=0;
	for (int i=1;i<=n;++i){
		ans+=vis[i];
	}
	for (int i=1;i<=u;++i){
		for (int j=1;j<=n;++j){
			if (i>=b[j]&&i%a[j]==b[j]%a[j]){
				vis[j]=1-vis[j];
			}
		}
		int cnt=0;
		for (int j=1;j<=n;++j){
			cnt+=vis[j];
//			cout<<vis[j];
		}
//		cout<<endl;
		ans=max(ans,cnt);
	}
	cout<<ans<<endl;
}