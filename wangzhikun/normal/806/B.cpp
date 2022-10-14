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

int n,a[150][10] = {0},tot[10] = {0},decision[10],ereq[10][10][5000];
int ans = 1e9;
void dfs(int depth){
	if(depth == 5){
		int score1 = 0,score2 = 0;
		int req = 0;
	//	cout<<"BEGIN"<<endl;
		for(int i=0;i<5;i++){
			int cs = decision[i]*500+500;
			if(a[0][i]!=-1){
				score1+=cs-a[0][i]*(cs/250);
			}
			if(a[1][i]!=-1){
				score2+=cs-a[1][i]*(cs/250);
			}
		//	cout<<"  i : "<<i<<' '<<score1<<' '<<score2<<endl;
		}
		if(score1<=score2)return;
		
		//cout<<score1<<' '<<score2<<endl;
		
		for(int i=0;i<5000;i++){
			int cc = 1;
			for(int j=0;j<5;j++){
				cc&=ereq[j][decision[j]][i];
			}
			if(cc){
			//	if(i<ans)cout<<i<<" : "<<decision[0]<<' '<<decision[1]<<' '<<decision[2]<<' '<<decision[3]<<' '<<decision[4]<<' '<<endl;
				ans = min(ans,i);
				break;
			}
		}
		return;
	}
	for(int i=0;i<6;i++){
		decision[depth] = i;
		dfs(depth+1);
	}
}
int main() {
	read(n);
	for(int i=0;i<n;i++){
		for(int j=0;j<5;j++){
			read(a[i][j]);
			if(a[i][j]>=0)tot[j]+=1;
		}
	}
	for(int i=0;i<5;i++){
		for(int j=0;j<6;j++){
			int cc = 1<<j;
			for(int k=0;k<5000;k++){
				int lb = (n+k)/cc/2+1;
				if(j == 5)lb = 0;
				int rb = (n+k)/cc;
				
				//if(i ==1 && j == 0 && k == 0)cout<<lb<<' '<<rb<<endl;
				if(a[0][i] == -1){
					if(lb<=rb && !(rb<tot[i] || lb>tot[i]))ereq[i][j][k] = 1;
				}else{
					if(lb<=rb && !(rb<tot[i] || lb>tot[i]+k))ereq[i][j][k] = 1;
				}
				
			}
		}
	}
	dfs(0);
	if(ans == 1e9)ans = -1;
	cout<<ans<<endl;
	return 0;
}