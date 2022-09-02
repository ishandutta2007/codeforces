#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
template<class T>void umin(T&x,const T&y){if(y<x)x=y;}
template<class T>void umax(T&x,const T&y){if(x<y)x=y;}
const int P=998244853;
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
const int N=300005,K=20,B=31;
int n,dp[N],hs[N][K],go[N][K],pw[K];
char s[N];
int mer(int k,int k1,int k2){
	return ad(k1,mu(k2,pw[k-1]));
}
void debug_out(int i){
	while(1){
		if(hs[i][0]==0)break;
		D("%c",hs[i][0]==1?'(':')');
		i=go[i][0];
	}
	D("\n");
}
void out(int i){
	while(1){
		if(hs[i][0]==0)break;
		putchar(hs[i][0]==1?'(':')');
		i=go[i][0];
	}
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	pw[0]=B;
	rep(i,1,K-1)pw[i]=mu(pw[i-1],pw[i-1]); // pw[i]=B^{2^i}
	scanf("%s",s+1),n=strlen(s+1);
	vector<int>st;
	per(i,n,1){
		if(s[i]=='('){
			go[i][0]=i+1;
			hs[i][0]=1;
			rep(j,1,K-1){
				hs[i][j]=mer(j,hs[i][j-1],hs[go[i][j-1]][j-1]);
				go[i][j]=go[go[i][j-1]][j-1];
			}
			if(!st.empty()){
				int cur=st.back()+1;
				int k1=i,k2=cur;
				per(j,K-1,0){
					if(hs[k1][j]==hs[k2][j]){
						k1=go[k1][j],k2=go[k2][j];
					}
				}
				if(hs[k1][0]>hs[k2][0]){
					memcpy(hs[i],hs[cur],sizeof(hs[i]));
					memcpy(go[i],go[cur],sizeof(go[i]));
				}
				st.pop_back();
			}
		}else{
			go[i][0]=i+1;
			hs[i][0]=2;
			rep(j,1,K-1){
				hs[i][j]=mer(j,hs[i][j-1],hs[go[i][j-1]][j-1]);
				go[i][j]=go[go[i][j-1]][j-1];
			}
			st.pb(i);
		}
		/*D("i=%d: ",i);
		debug_out(i);*/
	}
	out(1);
	return 0;
}