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
int n,m;

int hsum[2020][2020] = {0},ssum[2020][2020] = {0};
int hsub[2020][2020],ssub[2020][2020];
int hdp[2020],sdp[2020];

char Mp[2020][2020];

int main() {
	read(n);read(m);
	
	for(int i=0;i<n;i++){
		cin>>Mp[i];
	}
	if(n == 1 && m == 1){
		cout<<1<<endl;
		return 0;
	}
	for(int i=0;i<n;i++)
		for(int j=m-1;j>=0;j--)
			hsum[i][j] = hsum[i][j+1]+(Mp[i][j] == 'R');
	
	for(int j=0;j<m;j++)
		for(int i=n-1;i>=0;i--)
			ssum[i][j] = ssum[i+1][j]+(Mp[i][j] == 'R');
	hsub[0][0] = sub(0,1);
	ssub[0][0] = sub(0,1);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int chdp = sub(hdp[i],hsub[i][j]),csdp = sub(sdp[j],ssub[i][j]);
			if(!(i == 0 && j == 0)){
				hdp[i] = chdp;
				sdp[j] = csdp;
			}
			//cout<<i<<' '<<j<<' '<<chdp<<' '<<csdp<<' '<<m-hsum[i][j+1]<<' '<<n-ssum[i+1][j]<<endl;
			if(i == n-1 && j == m-1){
				cout<<add(chdp,csdp)<<endl;
			}
			
			hdp[i] = add(hdp[i],csdp);
			hsub[i][m-hsum[i][j+1]] = add(hsub[i][m-hsum[i][j+1]],csdp);
			
			sdp[j] = add(sdp[j],chdp);
			ssub[n-ssum[i+1][j]][j] = add(ssub[n-ssum[i+1][j]][j],chdp);
		}
	}
	
	return 0;
}