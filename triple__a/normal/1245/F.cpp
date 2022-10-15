#include<bits/stdc++.h>
using namespace std;

int l,r;
bool pl[33],pr[33];
long long dp[33][2][2][2][2];

long long calc(int pos,bool lx,bool ux,bool ly,bool uy){
	if (pos==-1) return 1;
	if (dp[pos][lx][ux][ly][uy]!=-1) return dp[pos][lx][ux][ly][uy];
	long long ret=0;
	if (!pl[pos]||(lx&&ly)) ret+=calc(pos-1,lx,ux|pr[pos],ly,uy|pr[pos]);
	if ((lx||(!pl[pos]))&&(uy||pr[pos])) ret+=calc(pos-1,lx,ux|pr[pos],ly|(!pl[pos]),uy);
	if ((ly||(!pl[pos]))&&(ux||pr[pos])) ret+=calc(pos-1,lx|(!pl[pos]),ux,ly,uy|pr[pos]);
	dp[pos][lx][ux][ly][uy]=ret;
	return ret;
}
void prec(){
	memset(pl,0,sizeof(pl));
	memset(pr,0,sizeof(pr));
	int c1=0,c2=0;
	while (l){
		pl[c1++]=l&1;
		l>>=1;
	}
	while (r){
		pr[c2++]=r&1;
		r>>=1;
	}
	for (int i=0;i<33;++i){
		for (int j=0;j<2;++j){
			for (int k=0;k<2;++k){
				for (int u=0;u<2;++u){
					for (int v=0;v<2;++v){
						dp[i][j][k][u][v]=-1;
					}
				}
			}
		}
	}
}

int main(){
	int t;
	scanf("%d",&t);
	while (t--){
		scanf("%d%d",&l,&r);
		prec();
		printf("%lld\n",calc(32,0,0,0,0));
	}
	return 0;
}