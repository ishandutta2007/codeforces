#include<bits/stdc++.h>
using namespace std;
inline int in(){
	int x;
	scanf("%d",&x);
	return x;
}
const int N=2e5+5;
int n,a[N],b[N];
int mark[N];
void solve(){
	n=in();
	for(int i=1;i<=n;i++)a[i]=in(),mark[i]=0;
	int now=0;
	while(1){
		int mx=now,id;
		for(int i=1;i<=n;i++)if(!mark[i]&&mx<(now|a[i]))mx=now|a[i],id=i;
		if(mx==now)break;now=mx;
		printf("%d ",a[id]),mark[id]=1;
	}
	for(int i=1;i<=n;i++)if(!mark[i])printf("%d ",a[i]);
	puts("");
}
int main(){
	int t=in();
	while(t--)solve();
	return 0;
}