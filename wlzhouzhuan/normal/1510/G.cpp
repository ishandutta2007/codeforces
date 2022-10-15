#include<bits/stdc++.h>
using namespace std;
#define N 233
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int T,n,k,dep[N],f[N],vis[N];
int mx,pos;
vector<int> ans;
void Solve(){
	mx=0,pos=1;
	vis[1]=0;
	for(int i=2;i<=n;++i){
		f[i]=read();
		vis[i]=0;
		dep[i]=dep[f[i]]+1;
		if(dep[i]>mx){
			mx=dep[i],pos=i;
		}
	}	
	int mn=min(k-1,mx);
	printf("%d\n",2*(k-1)-mn);
	ans.clear();
	for(int i=1;i<=n;++i){
		if(dep[i]==mn){
			for(int u=i;u;u=f[u]){
				ans.push_back(u);
				vis[u]=1;
			}
			reverse(ans.begin(),ans.end());
			break;
		}
	}	
	if(k-1>mx){
		int res=(k-1)-mx;
		while(res--){
			for(int i=1;i<=n;++i){
				if(vis[i])continue;
				if(vis[f[i]]){
					vis[i]=1;
					auto it=ans.begin();		
					while((*it)!=f[i])++it;
					ans.insert(++it,i);
					it=ans.begin();
					while((*it)!=i)++it;
					ans.insert(++it,f[i]);
					break;
				}
			}
		}		
	}
	for(auto x:ans){
		printf("%d ",x);
	}
	printf("\n");
}
int main(){
	T=read();
	while(T--){
		n=read(),k=read();
		Solve();
	}
	return 0;
}