#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();int f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}

int n,q;
char ma[200030],fc[3][1010];
int nxt[200030][30];
int fa[3][1010],cnt[3],cp[3],qpos[1010][3] = {0};
int main() {
	read(n);read(q);
	cin>>ma;
	for(int i=0;i<30;i++)nxt[200020][i] = n+1;
	for(int i=200020-1;i>=0;i--){
		memcpy(nxt[i],nxt[i+1],sizeof(nxt[i]));
		if(i<n)nxt[i][ma[i]-'a'] = i;
	}
	//cout<<233<<endl;
	for(int i=0;i<q;i++){
		char op,cc;
		int pos;
		cin>>op>>pos;
		pos--;
		if(op == '+'){
			cin>>cc;
			fa[pos][cnt[pos]+1] = cp[pos];
			fc[pos][cnt[pos]+1] = cc;
			cnt[pos]+=1;
			cp[pos] = cnt[pos];
		}else{
			cp[pos] = fa[pos][cp[pos]];
		}
	//	cout<<i<<' '<<cp[0]<<' '<<cp[1]<<' '<<cp[2]<<endl;
		memcpy(qpos[i],cp,sizeof(cp));
	}
	
	vector< vector<int> > dp[1010];
	
	for(int i=0;i<=cnt[0];i++){
		dp[i].resize(cnt[1]+5);
		for(int j=0;j<=cnt[1];j++)dp[i][j].resize(cnt[2]+5);
	}
	
	dp[0][0][0] = -1;
	
	for(int i=0;i<=cnt[0];i++){
		for(int j=0;j<=cnt[1];j++){
			for(int k=0;k<=cnt[2];k++){
				if(i+j+k == 0)continue;
				dp[i][j][k] = n+10;
				if(i)dp[i][j][k] = min(nxt[dp[fa[0][i]][j][k]+1][fc[0][i]-'a'],dp[i][j][k]);
				if(j)dp[i][j][k] = min(nxt[dp[i][fa[1][j]][k]+1][fc[1][j]-'a'],dp[i][j][k]);
				if(k)dp[i][j][k] = min(nxt[dp[i][j][fa[2][k]]+1][fc[2][k]-'a'],dp[i][j][k]);
			}
		}
	}
	
	for(int i=0;i<q;i++){
		if(dp[qpos[i][0]][qpos[i][1]][qpos[i][2]]<n){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}