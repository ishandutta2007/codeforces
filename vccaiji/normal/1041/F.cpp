#include<bits/stdc++.h>
using namespace std;
int n,m,sss;
int a[110000];
int b[110000];
map<int,int> mp; 
int ans=0;
int main(){
	scanf("%d%d",&n,&sss);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	scanf("%d%d",&m,&sss);
	for(int i=1;i<=m;i++) scanf("%d",&b[i]);
	for(int i=1;i<=n;i++){
		if(mp.count(a[i])) mp[a[i]]++;
		else mp[a[i]]=1;
	}
	for(int i=1;i<=m;i++){
		if(mp.count(b[i])) mp[b[i]]++;
		else mp[b[i]]=1;
	}
	for(int i=1;i<=n;i++) ans=max(ans,mp[a[i]]);
	for(int i=1;i<=m;i++) ans=max(ans,mp[b[i]]);
	for(int i=0;i<30;i++){
		mp.clear();
		for(int j=1;j<=n;j++){
			int t=(a[j]&((1<<(i+1))-1));
			if(mp.count(t)) mp[t]++;
			else mp[t]=1;
		}
		for(int j=1;j<=m;j++){
			int t=((b[j]+(1<<i))&((1<<(i+1))-1));
			if(mp.count(t)) mp[t]++;
			else mp[t]=1;
		}
		for(int j=1;j<=n;j++){
			int t=(a[j]&((1<<(i+1))-1));
			ans=max(ans,mp[t]);
		}
		for(int j=1;j<=m;j++){
			int t=((b[j]+(1<<i))&((1<<(i+1))-1));
			ans=max(ans,mp[t]);
		}
	}
	printf("%d",ans);
	return 0;
}