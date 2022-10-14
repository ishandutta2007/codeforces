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

int h,w,a[1010][1010];
int mod = 1e9+7;
inline int mul(int x,int y){return 1ll*x*y%mod;}
int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
int sq(int x){return 1ll*x*x%mod;}
int pow(int a,int b){return b == 0 ? 1 : ( b&1 ? mul(a,sq(pow(a,b/2))) : sq(pow(a,b/2)));}

int main() {
	read(h);read(w);
	int cu = 0;
	for(int i=0;i<h;i++){
		int cc = 0;
		read(cc);
		for(int j=0;j<cc;j++){
			a[i][j] = 1;
		}
		a[i][cc] = -1;
	}
	for(int i=0;i<w;i++){
		int cc = 0;
		read(cc);
		for(int j=0;j<cc;j++){
			if(a[j][i] == -1){
				cout<<0<<endl;
				return 0;
			}
			a[j][i] = 1;
		}
		if(a[cc][i] == 1){
			cout<<0<<endl;
			return 0;
		}
		a[cc][i] = -1;
	}
	for(int i=0;i<h;i++)for(int j=0;j<w;j++)cu+=(a[i][j] == 0);
	cout<<pow(2,cu)<<endl;
	return 0;
}