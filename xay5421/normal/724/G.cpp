// author: xay5421
// created: Mon Nov  8 19:52:36 2021
#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
using LL=long long;
template<class T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<class T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int P=1e9+7;
int ad(int k1,int k2){return k1+=k2-P,k1+=k1>>31&P;}
int su(int k1,int k2){return k1-=k2,k1+=k1>>31&P;}
int mu(int k1,int k2){return 1LL*k1*k2%P;}
void uad(int&k1,int k2){k1+=k2-P,k1+=k1>>31&P;}
void usu(int&k1,int k2){k1-=k2,k1+=k1>>31&P;}
template<class... T>int ad(int k1,T... k2){return ad(k1,ad(k2...));}
template<class... T>int su(int k1,T... k2){return su(k1,ad(k2...));}
template<class... T>int mu(int k1,T... k2){return mu(k1,mu(k2...));}
template<class... T>void uad(int&k1,T... k2){return uad(k1,ad(k2...));}
template<class... T>void usu(int&k1,T... k2){return usu(k1,ad(k2...));}
int po(int k1,int k2){
	int k3=1;
	for(;k2;k2>>=1,k1=mu(k1,k1))if(k2&1)k3=mu(k3,k1);
	return k3;
}
const int N=100005;
int n,m,vis[N],cnt[65][2],w;
LL b[65],dis[N];
vector<pair<int,LL> >e[N];
void ps(LL x){
	per(i,60,0)if(x>>i&1){
		if(!b[i]){
			w=ad(w,w);
			b[i]=x;
			return;
		}
		x^=b[i];
	}
}
void dfs(int k1,int k2,LL k3){
	vis[k1]=1;
	dis[k1]=k3;
	per(i,60,0){
		++cnt[i][k3>>i&1];
	}
	for(auto x:e[k1])if(x.first!=k2){
		if(!vis[x.first]){
			dfs(x.first,k1,k3^x.second);
		}else{
			ps(k3^x.second^dis[x.first]);
		}
	}
}
int main(){
	rd(n),rd(m);
	rep(i,1,m){
		int k1,k2;
		LL k3;
		rd(k1),rd(k2),rd(k3);
		e[k1].eb(k2,k3),e[k2].eb(k1,k3);
	}
	int ans=0;
	rep(i,1,n)if(!vis[i]){
		memset(b,0,sizeof(b));
		w=(P+1)/2;
		memset(cnt,0,sizeof(cnt));
		dfs(i,0,0);
		array<bool,65>vis={0};
		per(j,60,0)if(b[j])per(k,j,0)if(b[j]>>k&1)vis[k]=1;
		per(j,60,0){
			if(vis[j]){
				uad(ans,mu(int(1LL*(cnt[j][0]+cnt[j][1])*(cnt[j][0]+cnt[j][1]-1)/2%P),w,int((1LL<<j)%P)));
			}else{
				uad(ans,mu(cnt[j][0],cnt[j][1],ad(w,w),int((1LL<<j)%P)));
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}