#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
using LL=long long;
const int N=1000005;
int n,pos[N],go[N],ch[N][2],sz[N];
LL K,a[N];
int main(){
	scanf("%d%lld",&n,&K);
	rep(i,2,n){
		int fa;
		LL w;
		scanf("%d%lld",&fa,&w);
		a[i]=a[fa]^w;
	}
	fill(pos+1,pos+1+n,1);
	fill(go+1,go+1+n,1);
	LL ans=0;
	per(bit,63,0){
		rep(i,1,n){
			ch[i][0]=ch[i][1]=sz[i]=0;
		}
		int ind=0;
		rep(i,1,n){
			if(!ch[pos[i]][a[i]>>bit&1]){
				ch[pos[i]][a[i]>>bit&1]=++ind;
			}
			++sz[ch[pos[i]][a[i]>>bit&1]];
		}
		LL tot=0;
		rep(i,1,n){
			if(go[i]&&ch[go[i]][a[i]>>bit&1]){
				tot+=sz[ch[go[i]][a[i]>>bit&1]];
			}
		}
		rep(i,1,n){
			pos[i]=ch[pos[i]][a[i]>>bit&1];
		}
		if(K<=tot){
			rep(i,1,n){
				if(go[i]){
					go[i]=ch[go[i]][a[i]>>bit&1];
				}
			}
		}else{
			ans^=1LL<<bit;
			K-=tot;
			rep(i,1,n){
				if(go[i]){
					go[i]=ch[go[i]][~a[i]>>bit&1];
				}
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}