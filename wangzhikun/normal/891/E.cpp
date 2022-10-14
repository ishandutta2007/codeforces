#include <queue>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> poly;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();int f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}
int mod = 1e9+7;
inline int sq(int x){return 1ll*x*x%mod;}
inline int sub(int a,int b){return a<b?a-b+mod:a-b;}
inline int add(int a,int b){return a+b>=mod?a+b-mod:a+b;}
inline int mul(int a,int b){return 1ll*a*b%mod;}
inline int pow(int a,int b){if(b == 0)return 1;return b&1?mul(sq(pow(a,b/2)),a):sq(pow(a,b/2));}
inline int inv(int a){return pow(a,mod-2);}
const int N = 270000;
int rts[N],rev[N],fftmxl = 18,fftmx = 1<<fftmxl;
unordered_map<ll,int> ump;
void mul(poly& a,const poly& b){
	static int cc1[N],cc2[N];
	int asz = a.size(),bsz = b.size();
	int csz = asz+bsz-1;
	memset(cc1,0,csz*4);
	for(int i=0;i<asz;i++)for(int j=0;j<bsz;j++)cc1[i+j] = add(cc1[i+j],mul(a[i],b[j]));
	a.resize(csz);
	for(int i=0;i<csz;i++)a[i] = cc1[i];
	return;
}
int cc,n,k,fac[N];
poly pols[100010];
int main() {
	read(n);read(k);
	fac[0] = 1;
	for(int i=0;i<n;i++){
		read(cc);
		pols[i].push_back(1);pols[i].push_back(cc);
	}
	for(int i=2;(i>>1)<n;i*=2)for(int j=0;j+(i>>1)<n;j+=i)mul(pols[j],pols[j+(i>>1)]);
	int ans = 0,coef = 1,invn = inv(n);
	for(int i=n-1;i>=0;i--){
		coef = mul(coef,mul(k-(n-1-i),invn));
		if((n-i)&1)ans = add(ans,mul(pols[0][i],coef));
		else ans = sub(ans,mul(pols[0][i],coef));
	}
	cout<<ans<<endl;
	return 0;
}