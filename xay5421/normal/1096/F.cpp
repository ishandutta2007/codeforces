#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
typedef long long ll;
using namespace std;

template <typename T>
void read(T &x){
	int fl=0,ch;
	while (ch=getchar(),ch<48||57<ch) fl^=!(ch^45); x=(ch&15);
	while (ch=getchar(),47<ch&&ch<58) x=(x+(x<<2)<<1)+(ch&15);
	if (fl) x=-x;
}

template <typename T>
void print(T x){
	if (x<0) x=-x,putchar('-');
	if (x>9) print(x/10);
	putchar(x%10+48);
}

template <typename T>
void print(T x,int ch){
	print(x),putchar(ch);
}

template <typename T>
T max(const T &x,const T &y){return x<y?y:x;}

template <typename T>
T min(const T &x,const T &y){return x<y?x:y;}

const int P=998244353;
const int N=200005;

int n,tot,ans,fac=1,cnt,inv;
int a[N],tr[N],sum[N];
bool vis[N];
inline void add(int x){
	for (int i=x;i<=n;i+=i&-i) tr[i]++;
}
inline int query(int x){
	int ret=0;
	for (int i=x;i;i-=i&-i) ret+=tr[i];
	return ret; 
}
int fpow(int a,int b){
	int ret=1;
	while (b>1){
		if (b&1) ret=(ll)ret*a%P;
		b>>=1;
		a=(ll)a*a%P;
	}
	return (ll)a*ret%P;
}
signed main(){
	read(n);
	for (int i=1;i<=n;i++){
		read(a[i]);
		if (a[i]==-1) tot++,fac=1ll*fac*tot%P;
		else vis[a[i]]=1;
	}
	ans=1ll*tot*(tot-1)%P*fpow(4,P-2)%P;
	cnt=tot;
	for (int i=n;i>=1;i--){
		if (a[i]!=-1) ans=(ans+query(a[i]-1))%P,add(a[i]);
	}
	for (int i=1;i<=n;i++){
		sum[i]=sum[i-1];
		if (!vis[i]) sum[i]++;
	}
	inv=fpow(tot,P-2);
	for (int i=1;i<=n;i++){
		if (a[i]==-1) cnt--;
		else{
			ans=(ans+(1ll*sum[a[i]]*cnt%P+1ll*(tot-sum[a[i]])*(tot-cnt)%P)%P*inv%P)%P;
		}
	}
	print(ans,'\n');
	return 0;
}