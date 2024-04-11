#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define int long long
#define set0(x) memset(x,0,sizeof(x))
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();int f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}
const int N = 100010;
ll tim[N],n,blcs[N][5] = {0},blcn = 1,bonus = 0;
char terr[N];
signed main() {
	read(n);
	for(int i=0;i<n;i++) read(tim[i]);
	scanf("%s",terr);
	ll totf = 0,totw = 0,tots = 0;
	for(int i=0;i<n;i++){
		if(terr[i] == 'G'){
			totw+=tim[i];
			blcs[blcn][0]=tim[i];
		}
		if(terr[i] == 'W'){
			tots+=tim[i];
			blcs[blcn][1]=tim[i];
		}
		if(terr[i] == 'L'){
			totf+=tim[i];
			blcs[blcn][2] = tim[i];
		}
		blcn++;
	}
	blcn++;
	ll nwog = 0;
	for(int i=1;i<=blcn;i++){
		blcs[i][3] = blcs[i-1][3]+blcs[i][2];
	}
	int cs = 0,mn = 0,mxmake = 0;
	for(int i=1;i<=blcn;i++){
		if(blcs[i][1])cs = 1;
		mxmake+=blcs[i][0]+blcs[i][1];
		if(blcs[i][3]>mn+mxmake){
			ll cd = blcs[i][3]-mn-mxmake;
			mn+=cd;
			if(cs){
				bonus+=cd*3;
			}else{
				bonus+=cd*5;
			}
		}
		blcs[i][3]-=mn;
	}
	for(int i=blcn;i>1;i--){
		blcs[i-1][3] = max(blcs[i-1][3],blcs[i][3]-blcs[i][0]-blcs[i][1]);
	}
	for(int i=1;i<=blcn;i++){
		ll cwog=min(blcs[i-1][3]+blcs[i][0]+blcs[i][1]-blcs[i][3],blcs[i][0]*2);
		blcs[i][3] = blcs[i-1][3]+blcs[i][0]+blcs[i][1]-cwog;
		nwog+=cwog;
	}
	ll rlwk = totw,wtsw = mn+totw-nwog+tots-totf;
	cout<<totf+totw*5-nwog*2+tots*3-wtsw+bonus<<endl;
	return 0;
}