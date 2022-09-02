#include<bits/stdc++.h>
#define int long long
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=300005;
int n,k,ans,fa[N],tag[N],sz[N],sz2[N],go[N][2],ban[N];char s[N];vector<int>g[N];
int find(int k1){return fa[k1]==k1?k1:find(fa[k1]);}
int val(int k1){return ban[k1]?sz2[k1]:min(sz[k1]-sz2[k1],sz2[k1]);}
void mer(int k1,int k2){
	if(sz[k1]>sz[k2])swap(k1,k2);
	tag[k1]^=tag[k2];
	fa[k1]=k2;
	ban[k2]|=ban[k1];
	sz2[k2]+=sz2[k1];
	sz[k2]+=sz[k1];
}
int ask(int k1){
	int k2=0;
	while(1){
		k2^=tag[k1];
		if(k1==fa[k1])break;
		k1=fa[k1];
	}
	return k2;
}
signed main(){
	rd(n),rd(k);
	scanf("%s",s+1);
	for(int i=1;i<=k;++i){
		int m;rd(m);fa[i]=i,sz[i]=1,sz2[i]=0;
		for(int j=1;j<=m;++j){
			int k1;rd(k1);g[i].push_back(k1);
			if(!go[k1][0])go[k1][0]=i;else go[k1][1]=i;
		}
	}
	for(int i=1;i<=n;++i){
		if(!go[i][1]){
			if((s[i]^ask(go[i][0]))=='0'){
				int k1=find(go[i][0]);
				tag[k1]^=1;
				ans-=val(k1);
				sz2[k1]=sz[k1]-sz2[k1];
				ban[k1]=1;
				ans+=val(k1);
			}else{
				ans-=val(find(go[i][0]));
				ban[find(go[i][0])]=1;
				ans+=val(find(go[i][0]));
			}
		}else if(go[i][1]){
			int k1=find(go[i][0]),k2=find(go[i][1]);
			ans-=val(k1);if(k1!=k2)ans-=val(k2);
			if((s[i]^ask(go[i][0])^ask(go[i][1]))=='1'){
				if(k1!=k2){
					mer(k1,k2);
				}
				ans+=val(find(k2));
			}else{
				assert(k1!=k2);
				assert(!ban[k1]||!ban[k2]);
				if(!ban[k1])swap(k1,k2);
				tag[k2]^=1;
				sz2[k2]=sz[k2]-sz2[k2];
				mer(k1,k2);
				ans+=val(find(k2));
			}
		}
		pt(ans,'\n');
	}
	return 0;
}