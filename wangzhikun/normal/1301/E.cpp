#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();ll f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}
template<typename T, typename... Args> void read(T &first, Args& ... args) {
	read(first);
	read(args...);
}

int n,m,q;
char cmp[505][505];

struct Qsum{
	int val[505][505] = {0};
	void init(){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				val[i][j] = val[i][j-1]+val[i-1][j]-val[i-1][j-1]+val[i][j];
			}
		}
	}
	int query(int x1,int y1,int x2,int y2){
		//cout<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<' '<<val[x2][y2]<<' '<<val[x1-1][y2]<<' '<<val[x2][y1-1]<<' '<<val[x1-1][x2-1]<<endl;
		return val[x2][y2]-val[x1-1][y2]-val[x2][y1-1]+val[x1-1][y1-1];
	}
}Q[255];

vector<pii> Pos[550],PP[550];

bool ok(pii cc,int cv){
	if(cc.first-cv+1<1 || cc.second-cv+1<1 || cc.first+cv>n || cc.second+cv>m)return false;
	for(int i=1;i<=cv;i++){
		if(cmp[cc.first-cv+1][cc.second-cv+i]!='R')return false;
		if(cmp[cc.first-cv+i][cc.second-cv+1]!='R')return false;
		if(cmp[cc.first-cv+1][cc.second+i]!='G')return false;
		if(cmp[cc.first-cv+i][cc.second+cv]!='G')return false;
		if(cmp[cc.first+i][cc.second+cv]!='B')return false;
		if(cmp[cc.first+cv][cc.second+i]!='B')return false;
		if(cmp[cc.first+i][cc.second-cv+1]!='Y')return false;
		if(cmp[cc.first+cv][cc.second-cv+i]!='Y')return false;
	}
	return true;
}

int main() {
	read(n,m,q);
	for(int i=1;i<=n;i++){
		cin>>(cmp[i]+1);
	}
	for(int i=1;i<=n-1;i++){
		for(int j=1;j<=m-1;j++){
			if(cmp[i][j] == 'R' && cmp[i][j+1] == 'G' && cmp[i+1][j] == 'Y' && cmp[i+1][j+1] == 'B'){
				Pos[1].push_back(make_pair(i,j));
			}
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)Q[0].val[i][j] = 1;
	Q[0].init();
	for(int i=1;i<255;i++){
		if(!Pos[i].size())break;
		for(auto ct:Pos[i]){
			//cout<<i<<' '<<ct.first-i+1<<' '<<ct.second-i+1<<endl;
			Q[i].val[ct.first-i+1][ct.second-i+1]+=1;
			if(ok(ct,i+1)) Pos[i+1].push_back(ct);
		}
		Q[i].init();
	}
	int r1,c1,r2,c2;
	while(q--){
		read(r1,c1,r2,c2);
		int l = 0,r = min((r2-r1+1)/2,(c2-c1+1)/2)+1;
		while(l+1!=r){
			int i = (l+r)/2;
			if(Q[i].query(r1,c1,r2-i*2+1,c2-i*2+1)){
				l = i;
			}else{
				r = i;
			}
		}
		cout<<4*l*l<<"\n";
	}
	return 0;
}