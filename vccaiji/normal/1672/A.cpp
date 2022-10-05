/*#include<bits/stdc++.h>
using namespace std;
int _,n,a[210000];
int b[210000];
int c[210000];
int cnt[210000];
pair<int,int> aa[210000],bb[210000];
vector<int> s[210000];
int fa[210000];
int find(int i){
	if(fa[i]==i)return i;
	return fa[i]=find(fa[i]);
}
int vis[210000];
set<int> ;
int main(){
	cin>>_;
	while(_--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++)cin>>b[i];
		for(int i=1;i<=n;i++)aa[i]=make_pair(a[i],i);
		for(int i=1;i<=n;i++)bb[i]=make_pair(b[i],i);
		for(int i=1;i<=n;i++)c[aa[i].second]=bb[i].second;
		for(int i=1;i<=n;i++)s[i].clear();
		for(int i=1;i<=n;i++)s[a[i]].push_back(i);
		for(int i=1;i<=n;i++)vis[i]=0;
		int tot=0;
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				tot++;
				vis[i]=1;
				for(int j=c[i];j!=i;j=c[j])vis[j]=1;
			}
		}
		for(int i=1;i<=n;i++)cnt[i]=0;
		for(int i=1;i<=n;i++)cnt[a[i]]++;
		int maxx=0;
		for(int i=1;i<=n;i++)maxx=max(maxx,cnt[i]);
		for(int i=1;i<=n;i++)fa[i]=i;
		for(int )
		if(tot==maxx)printf("AC\n");
		else printf("WA\n");
	}
	return 0;
}*/ 
#include<bits/stdc++.h>
using namespace std;
int _,n,a[110];
bool u[1100];
int dp[51];
int main(){
	for(int i=1;i<=50;i++){
		for(int j=0;j<=110;j++)u[j]=0;
		for(int j=1;j<i;j++)u[dp[j]^dp[i-j]]=1;
		for(int j=0;;j++){
			if(!u[j]){
				dp[i]=j;
				break;
			}
		}
	}
	cin>>_;
	while(_--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		int o=0;
		for(int i=1;i<=n;i++)o^=dp[a[i]];
		if(o)cout<<"errorgorn\n";
		else cout<<"maomao90\n";
	}
	return 0;
}