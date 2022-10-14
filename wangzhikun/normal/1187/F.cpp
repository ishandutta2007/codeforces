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

int mod = 1000000007;
inline int mul(int x,int y){return 1ll*x*y%mod;}
int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
int sq(int x){return 1ll*x*x%mod;}
int pow(int a,int b){return b == 0 ? 1 : ( b&1 ? mul(a,sq(pow(a,b/2))) : sq(pow(a,b/2)));}


const int N = 200020;
int n,l[N],r[N],cu[N];
int main() {
	int a = 0,b = 0;
	read(n);
	for(int i=0;i<n;i++) read(l[i]);
	for(int i=0;i<n;i++)read(r[i]);
	for(int i=0;i<n-1;i++){
		int ml = max(l[i],l[i+1]),mr = min(r[i],r[i+1]);
		if(ml>mr)cu[i] = 1;
		else cu[i] = sub(1,mul(mr-ml+1,pow(mul(r[i]-l[i]+1,r[i+1]-l[i+1]+1),mod-2)));
		a = add(a,cu[i]);
	}
	int csu = 0;
	for(int i=1;i<n-1;i++){
		int cuu = 1;
		int ml3 = max(l[i-1],max(l[i],l[i+1])),mr3 = min(r[i-1],min(r[i],r[i+1]));
		int cho3 = pow(mul(r[i-1]-l[i-1]+1,mul(r[i+1]-l[i+1]+1,r[i]-l[i]+1)),mod-2);
		if(ml3<=mr3) cuu = sub(cuu,mul(mr3-ml3+1,cho3));
		int ml2 = max(l[i-1],l[i]),mr2 = min(r[i-1],r[i]);
		int isec = max(0,mr3-ml3+1);
		if(ml2<=mr2){
			cuu = sub(cuu,mul(cho3,mul(mr2-ml2+1-isec,r[i+1]-l[i+1]+1)));
			cuu = sub(cuu,mul(cho3,mul(isec,r[i+1]-l[i+1])));
		}
		ml2 = max(l[i+1],l[i]),mr2 = min(r[i+1],r[i]);
		if(ml2<=mr2){
			cuu = sub(cuu,mul(cho3,mul(mr2-ml2+1-isec,r[i-1]-l[i-1]+1)));
			cuu = sub(cuu,mul(cho3,mul(isec,r[i-1]-l[i-1])));
		}
		b = add(b,mul(cu[i],csu));
		b = add(b,cuu);
		csu = add(csu,cu[i-1]);
	}
	cout<<add(1,add(mul(a,3),mul(b,2)))<<endl;
	return 0;
}

/*

a = x
b = 0.5x^2 -0.5x


ans = 2b+3a+1

*/