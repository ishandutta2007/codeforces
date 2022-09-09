#include <bits/stdc++.h>
using namespace std;
const int N=200050;
int go[N];
int Find(int x){return go[x]?go[x]=Find(go[x]):x;}
void Union(int x,int y){go[Find(x)]=Find(y);}
int las[N],a[N],cnt[N];
int main(){
	int n;
	scanf("%i %*i",&n);
	for(int i=1;i<=n;i++)scanf("%i",&a[i]),las[a[i]]=i,cnt[a[i]]++;
	int ans=0;
	for(int i=1,r=0,mx=0;i<=n;i++){
		if(i>r){
			ans+=mx;
			mx=cnt[a[i]];
			r=las[a[i]];
		}else{
			mx=max(mx,cnt[a[i]]);
			r=max(r,las[a[i]]);
		}
		if(i==n)ans+=mx;
	}
	printf("%i\n",n-ans);
	return 0;
}