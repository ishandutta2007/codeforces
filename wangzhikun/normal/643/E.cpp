//determined
#include <cmath>
#include <cstdio>
#include <cstring>
#include <complex>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <unordered_map>

#define set0(x) memset(x,0,sizeof(x))
#define debug(x) cerr<<#x<<'='<<x<<endl

using namespace std;
typedef long long ll;

template<typename T> void read(T &x){
	x = 0;char ch = getchar();int f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();};
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}
	x*=f;
}

int q,x,y,cnt = 1,fa[500050];
double dp[500050][60];

int main(){
	cout<<setprecision(15)<<fixed;
	read(q);
	for(int i=0;i<60;i++) dp[1][i] = 1;
	while(q--){
		read(x);read(y);
		if(x == 1){
			cnt+=1;
			fa[cnt] = y;
			for(int i=0;i<60;i++) dp[cnt][i] = 1;
			double la = 1;
			int cp = cnt;
			for(int i=0;i<60;i++){
				double nla = dp[fa[cp]][i];
				if(i == 0) dp[fa[cp]][i] = dp[fa[cp]][i]*0.5;
				else dp[fa[cp]][i] = dp[fa[cp]][i]/((la+1)/2)*((dp[cp][i-1]+1)/2);
				cp = fa[cp];
				la = nla;
			}
		}else{
			double ans = 0;
			for(int i=0;i<60;i++)ans+=1-dp[y][i];
			cout<<ans<<"\n";
		}
	}
	return 0;
}