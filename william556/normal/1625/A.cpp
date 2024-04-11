#include<bits/stdc++.h>
using namespace std;
inline int in(){
	int x;
	scanf("%d",&x);
	return x;
}
int t,n,l;
int cnt[31];
void solve(){
	for(int i=0;i<30;i++)cnt[i]=0;
	n=in(),l=in();
	for(int i=1;i<=n;i++){
		int x=in();
		for(int j=0;j<30;j++)if(x&(1<<j))cnt[j]++;
	}
	int ans=0;
	for(int i=0;i<30;i++){
		if(cnt[i]>n/2)ans|=1<<i;
	}
	cout<<ans<<endl;
}
int main(){
	t=in();
	while(t--)solve();
	return 0;
}