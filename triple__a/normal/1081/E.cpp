#include<bits/stdc++.h>
using namespace std;

const int maxn=100007;

int n;
long long a[maxn],cnt=0;
bool ck(int u){
	int x=sqrt(a[u]);
	for (int i=x;i>0;--i){
		if (a[u]%i) continue;
		int l=i,r=a[u]/i;
		if (l+r&1) continue;
		if ((r-l)/2<=cnt) continue;
		a[u-1]=1LL*(r-l)*(r-l)/4 - 1LL*cnt*cnt;
		cnt=(l+r)/2;
		return 1;
	}
	return 0;
} 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for (int i=2;i<=n;i+=2){
		cin>>a[i];
	}
	for (int i=2;i<=n;i+=2){
		if (ck(i)) continue;
		cout<<"No"<<endl;
		return 0;	
	}
	cout<<"Yes"<<endl;
	for (int i=1;i<=n;++i){
		cout<<a[i]<<" ";
	}
	return 0;
}