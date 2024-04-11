#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
const int N = 1e5+5;

int n,m,cnt=0,ans[50];
int a[N], b[N], c[50];
bool g[45][45];
string s;

void dfs(int beg,int x,int tot){
	c[tot] = x;
	ans[beg] = max(ans[beg], tot);
	if(ans[beg] >= ans[beg+1] + 1) return;
	if(tot + ans[x+1] <= ans[beg]) return;
	rep(y,x+1,m){
		bool flag = true;
		rep(i,1,tot)if(!g[c[i]][y]){
			flag = false; break;
		}
		if(flag) dfs(beg,y,tot+1);
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	cin>>n>>m;
	map<string, int> mp;
	mp.clear();
	
	set<int> st;
	memset(g,true,sizeof g);
	rep(i,1,n){
		cin>>a[i];
		if(a[i]==2){
			cin>>s;
			if(!mp[s]) mp[s] = ++cnt;
			st.insert(mp[s]);
		}else{
			for(auto x:st) for(auto y:st) if(x!=y) g[x][y] = false;
			st.clear();
		}
	}
	for(auto x:st) for(auto y:st) if(x!=y) g[x][y] = false;
	
	memset(ans,0,sizeof ans);
	rrep(i,m,1) dfs(i,i,1), ans[i] = max(ans[i], ans[i+1]);
	cout<<ans[1]<<endl;
	return 0;
}