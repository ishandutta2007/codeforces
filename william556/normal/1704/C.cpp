#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int in(){
	int x;
	scanf("%d",&x);
	return x;
}
const int N=1e5+5;
int n,m,a[N],b[N];
void solve(){
	n=in(),m=in();
	for(int i=1;i<=m;i++)a[i]=in();
	if(m==1){
		puts("2");
		return;	
	}
	sort(a+1,a+m+1);
	for(int i=2;i<=m;i++)b[i]=a[i]-a[i-1]-1;
	b[1]=a[1]+n-a[m]-1;
	sort(b+1,b+m+1,greater<int>());
	long long ans=m;
	for(int i=1;i<=m;i++){
		int v=i*4-3;
		if(b[i]==v)ans+=b[i]-1;
		else ans+=min(b[i],i*4-3);			
	}
	printf("%lld\n",ans);
}
int main(){
	int t=in();
	while(t--)solve();
	return 0;
}