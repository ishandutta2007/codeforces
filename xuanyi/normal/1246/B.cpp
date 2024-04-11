//by xay5421 2449670833@qq.com
#include<set>
#include<map>
#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
//#define int long long
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
#define debug(...) fprintf(stderr,__VA_ARGS__)
//#define debug(...) ((void)0)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long ll;typedef unsigned long long ull;typedef std::pair<int,int> pii;
template<typename T>void rd(T&x){int f=0,c;while((c=getchar())<48||57<c)f^=!(c^45);x=(c&15);while(47<(c=getchar())&&c<58)x=x*10+(c&15);if(f)x=-x;}
template<typename T>inline void pt(T x){if(x<0)x=-x,putchar('-');if(x>9)pt(x/10);putchar(x%10+48);}
template<typename T>inline void pt(T x,int c){pt(x),putchar(c);}
template<typename T>inline T max(const T&x,const T&y){return x<y?y:x;}
template<typename T>inline T min(const T&x,const T&y){return x<y?x:y;}

const int P1=998244853,P2=19260817;

int n,k,p[100005],d[100005];bool ban[100005];std::map<pii,int>mmp;

void pre(){
	ban[0]=ban[1]=1;
	for(int i=2;i<=100000;++i){
		if(!ban[i]){
			p[++*p]=i;
			d[i]=i;
		}
		for(int j=1;j<=*p&&i*p[j]<=100000;++j){
			ban[i*p[j]]=1;
			d[i*p[j]]=p[j];
			if(i%p[j]==0)break;
		}
	}
}

pii geth(std::vector<int>a){
	std::pair<int,int>ha=(pii){1,1};
	for(int i=0;i<SZ(a);++i){
		ha.first=(ha.first*666233ll+a[i])%P1;
		ha.second=(ha.second*19260817ll+a[i])%P2;
	}
	return ha;
}

signed main(){
	pre();
	rd(n),rd(k);
	ll ans=0;
	rep(i,1,n){
		int x;rd(x);
		std::vector<int>now,tmp;
		while(x!=1){
			int y=d[x],z=0;
			while(x%y==0)x/=y,++z;
			z%=k;
			if(z)
				now.push_back(y),now.push_back(z);
			if((k-z)%k)
				tmp.push_back(y),tmp.push_back((k-z)%k);
		}
		pii ha=geth(tmp);
		if(mmp.count(ha)){
			ans+=mmp[ha];
//			pt(i,' ');
//			pt(ans,'\n');
		}
		++mmp[geth(now)];
	}
	pt(ans,'\n');
	return 0;
}