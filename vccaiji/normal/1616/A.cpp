#include<bits/stdc++.h>
using namespace std;
int n;
int a[1100000];
int cnt[110];
int main(){
	int _;
	cin>>_;
	while(_--){
		for(int i=0;i<=100;i++)cnt[i]=0;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++)cnt[abs(a[i])]++;
		int ans=0;
		if(cnt[0])ans++;
		for(int i=1;i<=100;i++)ans+=min(cnt[i],2);
		cout<<ans<<endl;
	} 
	return 0;
}