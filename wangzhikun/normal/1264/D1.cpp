#include <set>
#include <queue>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define debug(x) cerr<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();ll f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}

int mod = 998244353;
inline int mul(int x,int y){return 1ll*x*y%mod;}
int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
int sq(int x){return 1ll*x*x%mod;}
int mpow(int a,int b){return b == 0 ? 1 : ( b&1 ? mul(a,sq(mpow(a,b/2))) : sq(mpow(a,b/2)));}


int fac[1000100],invfac[1000100];
int C(int n,int m){return mul(fac[n],mul(invfac[n-m],invfac[m]));}

int cntl[2020][2020],cntr[2020][2020];

int rl = 0,rr = 0,rq = 0,cl = 0,cr = 0,cq = 0;
char cnt[2020];

int main() {
	fac[0] = 1;
	for(int i=1;i<=1000010;i++)fac[i] = mul(i,fac[i-1]);
	invfac[1000010] = mpow(fac[1000010],mod-2);
	for(int i=1000010-1;i>=0;i--)invfac[i] = mul(i+1,invfac[i+1]);
	cin>>cnt;
	int n = strlen(cnt);
	for(int i=0;i<n;i++){
		if(cnt[i] == '('){
			rl++;
		}
		if(cnt[i] == ')'){
			rr++;
		}
		if(cnt[i] == '?'){
			rq++;
		}
	}
	int lcnt[2020],rcnt[2020];
	int ans = 0;
	for(int i=0;i<n;i++){
		if(cnt[i] == '('){
			cl++;rl--;
			set0(lcnt);set0(rcnt);
			int cf = mpow(2,cq+rq);
			for(int i=0;i<=cq;i++) lcnt[cl+i] = C(cq,i);
			for(int i=0;i<=rq;i++) rcnt[rr+i] = C(rq,i);
			int cs2 = 0;
			for(int a=0;a<=n;a++){
				cf = sub(cf,mul(lcnt[a],cs2));
				cs2 = add(cs2,rcnt[a]);
			}
			ans = add(ans,cf);
		}
		if(cnt[i] == ')'){
			cr++;rr--;
		}
		if(cnt[i] == '?'){
			cq++;rq--;
			cq--;
			cl++;
			//cout<<cq<<' '<<rq<<' '<<cl<<' '<<rr<<endl;
			set0(lcnt);set0(rcnt);
			int cf = mpow(2,cq+rq);
			for(int i=0;i<=cq;i++) lcnt[cl+i] = C(cq,i);
			for(int i=0;i<=rq;i++) rcnt[rr+i] = C(rq,i);
			int cs2 = 0;
			for(int a=0;a<=n;a++){
				cf = sub(cf,mul(lcnt[a],cs2));
				cs2 = add(cs2,rcnt[a]);
			}
			ans = add(ans,cf);
			cq++;
			cl--;
		}
		//cout<<i<<' '<<ans<<endl;
	}
	cout<<ans<<endl;
	return 0;
}