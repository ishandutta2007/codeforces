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
typedef pair<int,int> pii;
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


int n,m,dis[100010],vis[100010] = {0},len[100010],mag[100010][10],u[100010],v[100010],sans[100010],ans[100010];
vector<pii> G[100010];
priority_queue<pii, vector<pii>, greater<pii>> Q;

struct walk{
	int edn,cu,srt,cv;
	bool operator < (const walk &rhs) const{
		return srt<rhs.srt;
	}
};
int main() {
	read(n);read(m);
	v[0] = 1;
	int cv = 1;
	for(int i=1;i<=100000;i++){
		len[i] = len[i/10]+1;
		int cl = len[i],ci = i;
		for(int j=cl-1;j>=0;j--){
			mag[i][j] = ci%10;
			ci/=10;
		}
	}
	for(int i=1;i<=m;i++){
		read(u[i]);read(v[i]);
		G[u[i]].push_back(make_pair(v[i],i));
		G[v[i]].push_back(make_pair(u[i],i));
	}
	Q.push(make_pair(0,1));
	while(!Q.empty()){
		pii cc = Q.top();Q.pop();
		if(vis[cc.second])continue;
		vis[cc.second] = 1;
		dis[cc.second] = cc.first;
		for(auto ct:G[cc.second]){
			Q.push(make_pair(cc.first+len[ct.second],ct.first));
		}
	}
	for(int i=1;i<=m;i++){
		if(dis[v[i]]<dis[u[i]])
			swap(u[i],v[i]);
	}
	vector<walk> q;
	for(auto ct:G[1]){
		if(len[ct.second]+dis[1] == dis[ct.first]){
			q.push_back((walk){ct.second,1,mag[ct.second][0],mag[ct.second][0]});
		}
	}
	while(1){
		//cout<<233<<endl;
		if(!q.size())break;
		sort(q.begin(),q.end());
		vector<walk> nq;
		int csr = 0;
		for(int i=0;i<q.size();i++){
			if(i && q[i].srt!=q[i-1].srt)csr+=1;
			if(q[i].cu == len[q[i].edn]){
				if(sans[v[q[i].edn]])continue;
				sans[v[q[i].edn]] = 1;
				ans[v[q[i].edn]] = q[i].cv;
				int cuv = v[q[i].edn];
				for(auto ct:G[cuv]){
					if(len[ct.second]+dis[cuv] == dis[ct.first]){
						nq.push_back((walk){ct.second,1,csr*10+mag[ct.second][0],add(mul(ans[cuv],10),mag[ct.second][0])});
					}
				}
			}else{
				nq.push_back((walk){q[i].edn,q[i].cu+1,csr*10+mag[q[i].edn][q[i].cu],add(mul(q[i].cv,10),mag[q[i].edn][q[i].cu])});
			}
		}
		q = nq;
	}
	for(int i=2;i<=n;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}