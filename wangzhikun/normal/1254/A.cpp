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

int T;
string opt = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

int n,m,k;
char ipt[110][110],ans[110][110];
void solve(){
	cin>>n>>m>>k;
	int cnt = 0;
	memset(ans,0,sizeof(ans));
	for(int i=0;i<n;i++){
		cin>>ipt[i];
		for(int j=0;j<m;j++)cnt+=ipt[i][j] == 'R';
	}
	int ech = cnt/k,rcn = cnt-ech*k;
	if(rcn) ech+=1;
	int cp = 0,ccn = 0;
	for(int i=0;i<n;i++){
		if(i%2 == 0){
			for(int j=0;j<m;j++){
				ans[i][j] = opt[cp];
				ccn+=ipt[i][j] == 'R';
				if(ccn == ech && cp!=k-1){
					cp+=1;
					ccn =0;
					if(rcn){
						rcn--;
						if(rcn == 0)ech--;
					}
				}
			}
		}else{
			for(int j = m-1;j>=0;j--){
				ans[i][j] = opt[cp];
				ccn+=ipt[i][j] == 'R';
				if(ccn == ech && cp!=k-1){
					cp+=1;
					ccn =0;
					if(rcn){
						rcn--;
						if(rcn == 0)ech--;
					}
				}
			}
		}
		cout<<ans[i]<<endl;
	}
}
int main() {
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}