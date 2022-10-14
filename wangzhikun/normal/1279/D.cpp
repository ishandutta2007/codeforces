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

int n,prob[1000010],cnt[1000010];
int main() {
	read(n);
	for(int i=0;i<n;i++){
		int cc,cd;
		read(cc);
		int cprob = mpow(cc,mod-2);
		while(cc--){
			read(cd);
			prob[cd] = add(prob[cd],cprob);
			cnt[cd]+=1;
		}
	}
	int tot = mul(n,n),valid = 0;
	for(int i=0;i<1000010;i++){
		valid = add(valid,mul(prob[i],cnt[i]));
	}
	//cout<<tot<<' '<<valid<<endl;
	cout<<mul(valid,mpow(tot,mod-2))<<endl;
	return 0;
}