#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+1;
int n,a[N],h[N],t[N];
vector<int>mg[N];
signed main(){
	scanf("%lld", &n);
	for(int i=0;i<n;++i)scanf("%lld",&a[i]),h[i]=i-1,t[i]=i+1;
	for(int i=1;i<n;++i)mg[a[i]-a[i-1]].push_back(i);
	for (int i=0;;++i){
		for (int j:mg[i])t[h[j]]=t[j],h[t[j]]=h[j];
		int s=i*i-a[0],x=0,y=s+i,j=i;
		for(int l=0;l<n;l=t[l]){
			while(j*(j+1)<a[l]+s)++j;
			x=max(x,j*j-a[l]),y=min(y,j*(j+1)-a[t[l]-1]);
		}
		if(x<=y){printf("%lld",x);exit(0);}
	}
}