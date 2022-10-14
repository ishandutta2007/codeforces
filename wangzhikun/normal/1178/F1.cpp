#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define debug(x) cerr<<#x<<'='<<x<<endl
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();int f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}

int mod = 998244353;
inline int mul(int x,int y){return 1ll*x*y%mod;}
int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
int sq(int x){return 1ll*x*x%mod;}
int pow(int a,int b){return b == 0 ? 1 : ( b&1 ? mul(a,sq(pow(a,b/2))) : sq(pow(a,b/2)));}


int n,a[550],dp[550][550];
int main() {
	read(n);read(n);
	for(int i=1;i<=n;i++){
		read(a[i]);
		dp[i][i] = 1;
	}
	for(int l=2;l<=n;l++){
		for(int li = 1;li+l-1<=n;li++){
			int ri = li+l-1;
			
			int mi = 2000,mp = 0;
			for(int j=li;j<=ri;j++){
				if(a[j]<mi){
					mi = a[j];
					mp = j;
				}
			}
			int cl = 0,cr = 0;
			if(mp == li)cl+=1;
			else cl = add(cl,dp[li][mp-1]);
			if(mp == ri)cr+=1;
			else cr = add(cr,dp[mp+1][ri]);
			for(int hf = li;hf<mp;hf++){
				if(hf == mp-1){
					cl = add(cl,mul(dp[li][hf],1));
				}else{
					cl = add(cl,mul(dp[li][hf],dp[hf+1][mp-1]));
				}
			}
			for(int hf = mp+1;hf<=ri;hf++){
				if(hf == mp+1){
					cr = add(cr,mul(dp[hf][ri],1));
				}else{
					cr = add(cr,mul(dp[mp+1][hf-1],dp[hf][ri]));
				}
			}
			//cout<<' '<<li<<' '<<ri<<' '<<cl<<' '<<cr<<endl;
			dp[li][ri] = mul(cl,cr);
		}
	}
	cout<<dp[1][n]<<endl;
	return 0;
}