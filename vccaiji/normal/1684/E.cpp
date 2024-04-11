#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[210000];
int b[210000];
bool in[210000];
bool chk(int x){
	int cnt=1;
	for(int i=2;i<=x;i++)if(a[i]!=a[i-1])cnt++;
	return min(n-x,k)>=a[x]+1-cnt;
}
map<int,int> s;
int u[210000];
int cal(int x){
	s.clear();
	for(int i=x+1;i<=n;i++)s[a[i]]++;
	int tot=0;
	for(auto ss : s)u[++tot]=ss.second;
	sort(u+1,u+tot+1);
	for(int i=1;i<=tot;i++){
		if(k<u[i])return tot-(i-1);
		k-=u[i];
	}
	return 0;
}
int main(){
	int _;
	cin>>_;
	while(_--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		int l=0,r=n;
		for(;l<r;){
			int md=(l+r)/2;
			if(chk(md+1)) l=md+1;
			else r=md;
		}
		cout<<cal(l)<<"\n";
	}
	return 0;
}