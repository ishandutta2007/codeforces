#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define set0(x) memset(x,0,sizeof(x))
#define debug(x) cerr<<#x<<'='<<x<<endl
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

int n;
int query(vector<int> S,vector<int> T,int v,int tlim = 1000){
	if(tlim == 0 || T.size() == 0)return 0;
	cout<<S.size()<<endl;
	for(int i=0;i<S.size();i++)cout<<S[i]<<' ';cout<<endl;
	tlim = min(tlim,(int)T.size());
	cout<<tlim<<endl;
	for(int i=0;i<tlim;i++)cout<<T[i]<<' ';cout<<endl;
	cout<<v<<endl;cout.flush();
	int ret;
	read(ret);
	return ret;
}
int fa[550];
pll du[550];
int main() {
	vector<int> cs,ct;
	read(n);
	cs.push_back(1);
	for(int i=2;i<=n;i++)ct.push_back(i);
	du[1] = MP(n,1);
	for(int i=2;i<=n;i++){
		du[i] = MP(query(cs,ct,i),i);
	}
	sort(du+1,du+n+1);
	vector<int> X;
	for(int i=1;i<=n;i++){
		int v = du[i].second;
		int ctot = query(cs,X,v);
		for(int j=0;j<ctot;j++){
			int l = 0,r = X.size();
			while(l+1!=r){
				int mid = (l+r)/2;
				if(query(cs,X,v,mid)){
					r = mid;
				}else{
					l = mid;
				}
			}
			fa[X[l]] = v;
			X.erase(X.begin()+l);
		}
		X.push_back(v);
	}
	cout<<"ANSWER"<<endl;
	for(int i=2;i<=n;i++)cout<<i<<' '<<fa[i]<<endl;
	cout.flush();
	return 0;
}