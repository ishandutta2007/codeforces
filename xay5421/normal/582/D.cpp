// author: xay5421
// created: Thu Mar 11 07:33:47 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long LL;
const int P=1e9+7;
int ad(int k1,int k2){return k1+=k2-P,k1+=k1>>31&P;}
int su(int k1,int k2){return k1-=k2,k1+=k1>>31&P;}
int mu(int k1,int k2){return 1LL*k1*k2%P;}
void uad(int&k1,int k2){k1+=k2-P,k1+=k1>>31&P;}
void usu(int&k1,int k2){k1-=k2,k1+=k1>>31&P;}
template<typename... T>int ad(int k1,T... k2){return ad(k1,ad(k2...));}
template<typename... T>void uad(int&k1,T... k2){return uad(k1,ad(k2...));}
template<typename... T>void usu(int&k1,T... k2){return usu(k1,ad(k2...));}
template<typename... T>int mu(int k1,T... k2){return mu(k1,mu(k2...));}
int po(int k1,int k2){
	int k3=1;
	for(;k2;k2>>=1,k1=mu(k1,k1))if(k2&1)k3=mu(k3,k1);
	return k3;
}
const int N=3505;
int p,alpha,f[N][N][2][2];
vector<int>num;
char s[N];
int F(int x){return 1LL*x*(x+1)/2%P;}
int dfs(int cur,int cnt,int up,int jw){
	if(cnt<0)cnt=0;
	if(cur<0)return !jw&&cnt==0;
	int&ans=f[cur][cnt][up][jw];
	if(ans!=-1)return ans;
	ans=0;
	int lim=up?num[cur]:p-1;
	assert(lim<p);
	if(!jw){
		uad(ans,mu(dfs(cur-1,cnt,0,0),F(lim)));
		uad(ans,mu(dfs(cur-1,cnt,up,0),lim+1));
		uad(ans,mu(dfs(cur-1,cnt-1,0,1),F(lim-1)));
		uad(ans,mu(dfs(cur-1,cnt-1,up,1),lim));
	}else{
		uad(ans,mu(dfs(cur-1,cnt,0,0),su(F(p-1),F(p-lim-1))));
		uad(ans,mu(dfs(cur-1,cnt,up,0),p-1-lim));
		uad(ans,mu(dfs(cur-1,cnt-1,0,1),su(F(p),F(p-lim))));
		uad(ans,mu(dfs(cur-1,cnt-1,up,1),p-lim));
	}
	//D("f[%d][%d][%d][%d]=%d\n",cur,cnt,up,jw,f[cur][cnt][up][jw]);
	return ans;
}
int main(){
	memset(f,-1,sizeof(f));
	scanf("%d%d%s",&p,&alpha,s+1);
	int len=strlen(s+1);
	if(len==1&&s[1]=='0'){puts("0");return 0;}
	rep(i,1,len)s[i]-='0';
	reverse(s+1,s+1+len);
	while(len){
		LL yu=0;
		for(int i=len;i>=1;--i){
			yu=yu*10+s[i];
			s[i]=yu/p;
			yu%=p;
		}
		num.push_back(yu);
		while(len&&!s[len])--len;
	}
	if(SZ(num)<alpha){puts("0");return 0;}
	printf("%d\n",dfs(SZ(num)-1,alpha,1,0));
	return 0;
}