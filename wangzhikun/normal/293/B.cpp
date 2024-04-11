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
int n,m,c;
int apr[15][15],mp[15][15],cnt[15],ans;
int rpn[15][15];
void dfs(int a,int b,int cways){
	//cout<<a<<' '<<b<<' '<<cways<<endl;
	if(a == n+1 && b == 1){
		ans = add(ans,cways);
		return;
	}
	if(mp[a][b]){
		apr[a][b] = 1<<mp[a][b];
		if((apr[a][b]&apr[a-1][b]) | (apr[a][b]&apr[a][b-1]))return;
		apr[a][b]|=apr[a-1][b]|apr[a][b-1];
		if(b!=m)dfs(a,b+1,cways);
		else dfs(a+1,1,cways);
		return;
	}
	int cv = -1,ccho = 0;
	for(int i=1;i<=c;i++){
		if(cnt[i] == 0){
			ccho+=1;
			cv = i;
		}else{
			apr[a][b] = 1<<i;
			if((1<<i)&rpn[a][b])continue;
			if((apr[a][b]&apr[a-1][b]) | (apr[a][b]&apr[a][b-1]))continue;
			apr[a][b]|=apr[a-1][b]|apr[a][b-1];
			cnt[i]+=1;
			if(b!=m)dfs(a,b+1,cways);
			else dfs(a+1,1,cways);
			cnt[i]-=1;
		}
	}
	//cout<<cv<<endl;
	if(cv!=-1 && ((1<<cv)&rpn[a][b]) == 0){
		apr[a][b] = 1<<cv;
		apr[a][b]|=apr[a-1][b]|apr[a][b-1];
		cnt[cv]+=1;
		if(b!=m)dfs(a,b+1,mul(cways,ccho));
		else dfs(a+1,1,mul(cways,ccho));
		cnt[cv]-=1;
	}
}

int main() {
	read(n);read(m);read(c);
	if(n+m-1>c){
		cout<<0<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
		cin>>mp[i][j];
		cnt[mp[i][j]]+=1;
		if(mp[i][j]){
			for(int ii=1;ii<=i;ii++)for(int jj=1;jj<=j;jj++)rpn[ii][jj]|=1<<mp[i][j];
		}
	}
	dfs(1,1,1);
	cout<<ans<<endl;
	return 0;
}