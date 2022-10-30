#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int n,m;
char p[4]={'A','C','G','T'};
vector<vector<char> >a,b,c;
int ans=1e9;
int res=0;
void upd(){
	if(res>=ans) return;
	ans=res;
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=m ;j++){
			b[i][j]=c[i][j];
		}
	}
}
void solve(){
	if(p[0]>p[1] || p[2]>p[3]) return;
	res=0;
	for(int i=1; i<=n ;i++){
		int tr=0,tw=0;
		for(int j=1; j<=m ;j++){
			int now=i%2*2+j%2;
			tr+=(p[now]!=a[i][j]);
			tw+=(p[now^1]!=a[i][j]);
			c[i][j]=p[now];
		}
		if(tr>tw){
			swap(tr,tw);
			for(int j=1; j<=m ;j++) c[i][j]=p[(i%2*2+j%2)^1];
		}
		res+=tr;
	}
	upd();
	res=0;
	for(int j=1; j<=m ;j++){
		int tr=0,tw=0;
		for(int i=1; i<=n ;i++){
			int now=j%2*2+i%2;
			tr+=(p[now]!=a[i][j]);
			tw+=(p[now^1]!=a[i][j]);
			c[i][j]=p[now];
		}
		if(tr>tw){
			swap(tr,tw);
			for(int i=1; i<=n ;i++) c[i][j]=p[(j%2*2+i%2)^1];
		}
		res+=tr;
	}
	upd();
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	a.resize(n+1);b.resize(n+1);c.resize(n+1);
	for(int i=1; i<=n ;i++){
		a[i].resize(m+1);b[i].resize(m+1);c[i].resize(m+1);
		for(int j=1; j<=m ;j++) cin >> a[i][j];
	}
	do{
		solve();
	}while(next_permutation(p,p+4));
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=m ;j++) cout << b[i][j];
		cout << '\n';
	}
}