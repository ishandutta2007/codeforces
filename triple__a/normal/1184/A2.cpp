#include<bits/stdc++.h>
using namespace std;
 
const int maxn=300007;
int n;
char a[maxn];
bool fg[maxn];
 
int gcd(int u,int v){
	return v?gcd(v,u%v):u;
}
 
bool check(int t){
	for (int i=1;i<=t;++i){
		int ret=0;
		for (int j=i;j<=n;j+=t){
			if (a[j-1]=='1') ret++;
		}
//		cout<<t<<" "<<ret<<endl;
		if (ret%2) return true;
	}
	return false;
}
 
int main(){
	memset(fg,0,sizeof(fg));
	cin>>n;
	cin>>a;
	int ret=0,ans=0;
	for (int i=0;i<n;++i){
		if (a[i]=='1'){
			ret++;
		}
	}
	if (ret%2){
		printf("0");
		return 0;
	}
	if (ret==0){
		printf("%d",n);
		return 0;
	}
	int u=sqrt(n);
	for (int i=2;i<=u;++i){
		if (n%i==0){
			if (check(i)){
				fg[i]=1;
			}
			if (check(n/i)){
				fg[n/i]=1;
			}
		}
	}
	ans=0;
	for (int i=1;i<n;++i){
		if (!fg[gcd(i,n)]){
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}