#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring> 
using namespace std;

typedef long long ll;
int n,k;
const int maxn=300007;

struct arr{
	ll ans;
	int pos;
	friend bool operator<(arr x,arr y){
		return x.ans<y.ans; 
	} 
}s[maxn];

int a[maxn];
bool vis[maxn];
int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	s[0].ans=0;
	s[0].pos=0;
	for (int i=1;i<n;++i){
		s[i].ans=s[i-1].ans+a[i];
		s[i].pos=i;
	}
	sort(s+1,s+n);
	memset(vis,0,sizeof(vis));
	for (int i=1;i<k;++i){
		vis[s[i].pos]=1;
	}
	ll ret=0;
	int j=1;
	for (int i=1;i<=n;++i){
		ret+=(ll)j*a[i];
		if (vis[i]) j++;
	}
	printf("%lld\n",ret);
	return 0;
}