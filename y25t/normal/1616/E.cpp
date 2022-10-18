#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f3f3f3f3f
#define N 100005

int T;

int n;
char a[N],b[N];

std::vector<int> V[26];

int t[N];
inline int lb(int x){
	return x&-x;
}
inline void add(int x){
	for(;x;x-=lb(x))
		t[x]++;
}
inline int sum(int x){
	int res=0;
	for(;x<=n;x+=lb(x))
		res+=t[x];
	return res;
}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%s%s",&n,a+1,b+1);
		for(int i=0;i<26;i++)
			V[i].clear();
		for(int i=n;i;i--)
			V[a[i]-'a'].push_back(i);
		for(int i=1;i<=n;i++)
			t[i]=0;
		ll ans=inf,s=0;
		for(int i=1;i<=n;i++){
			int c=b[i]-'a';
			for(int x=c-1;~x;x--)
				if(V[x].size()){
					int p=V[x].back();
					ans=std::min(ans,s+p+sum(p)-i);
				}
			if(V[c].size()){
				int p=V[c].back();
				V[c].pop_back();
				s+=p+sum(p)-i;
				add(p);
			}
			else
				break;
		}
		printf("%lld\n",ans<inf?ans:-1);
	}
}