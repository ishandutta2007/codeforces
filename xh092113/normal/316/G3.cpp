#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long

const int N = 50000;
const int SN = 550000;

In int read(){
	int s = 0,ww = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-')ww = -1;ch = getchar();}
	while('0' <= ch && ch <= '9'){s = 10 * s + ch - '0';ch = getchar();}
	return s * ww;
}

int n,l[10+5],r[10+5],loc[SN+5];
char s[N+5];

struct SAM{
	int cnt,nx[2*SN+5][26],len[2*SN+5],fail[2*SN+5];
	int f[2*SN+5][11];
	void clear(){
		fail[0] = -1;
	}
	int extend(int last,int id){
//cout<<"extend: last="<<last<<" id="<<(char)('a'+id)<<endl;
		int cur = ++cnt;
		int p;
		len[cur] = len[last] + 1;
		for(p = last;p != -1 && !nx[p][id];p = fail[p])nx[p][id] = cur;
		if(p == -1)fail[cur] = 0;
		else{
			int q = nx[p][id];
			if(len[q] == len[p] + 1)fail[cur] = q;
			else{
				int clone = ++cnt;
				len[clone] = len[p] + 1;
				fail[clone] = fail[q];
				memcpy(nx[clone],nx[q],sizeof(nx[clone]));
				fail[cur] = fail[q] = clone;
				for(;p != -1 && nx[p][id] == q;p = fail[p])nx[p][id] = clone;
			}
		} 
/*for(rg int i = 0;i <= cnt;i++){
	cout<<"i="<<i<<" len="<<len[i]<<" fail[i]="<<fail[i];
	for(rg int j = 0;j < 5;j++)cout<<" nx:"<<(char)('a'+j)<<"="<<nx[i][j]<<" ";cout<<endl;
}*/
		return cur;
	}
	In ll count(int u){
		return (ll)len[u] - (ll)len[fail[u]];
	}
	vector<int>link[2*SN+5];
	void dfs(int u){
		for(rg int i = 0;i < link[u].size();i++){
			int v = link[u][i];
			dfs(v);
			for(rg int k = 0;k <= n;k++)f[u][k] += f[v][k];
		}
	}
	void solve(){
		ll ans = 0;
/*for(rg int i = 0;i <= cnt;i++){
	for(rg int j = 0;j <= n;j++)cout<<f[i][j]<<" ";cout<<endl;
}	
cout<<endl;*/
		for(rg int i = 1;i <= cnt;i++)link[fail[i]].push_back(i);
		dfs(0);
/*for(rg int i = 0;i <= cnt;i++){
	for(rg int j = 0;j <= n;j++)cout<<f[i][j]<<" ";cout<<endl;
}*/
		for(rg int i = 1;i <= cnt;i++){
			ll b = 1;
			for(rg int j = 0;j <= n;j++)if(f[i][j] < l[j] || f[i][j] > r[j]){
				b = 0;break;
			}
//if(b)cout<<count(i)<<endl;
			ans += b * count(i);
		}
		cout << ans << endl;
	}
}S;

struct Trie{
	int nx[SN+5][26];
	vector<int>flag[SN+5];
	int cnt;
	void insert(char s[],int id){
		int ls = strlen(s + 1);
		int u,i;
		for(u = 0,i = 1;i <= ls;i++){
			if(!nx[u][s[i]-'a'])nx[u][s[i]-'a'] = ++cnt;
			u = nx[u][s[i]-'a'];
			flag[u].push_back(id);
		}
	}
	queue<int>q;
	void build(){
		S.clear();
		q.push(0);
		while(!q.empty()){
			int u = q.front();
			q.pop();
			for(rg int i = 0;i < 26;i++)if(nx[u][i]){
				int v = nx[u][i];
				loc[v] = S.extend(loc[u],i);
				q.push(v);
				for(rg int j = 0;j < flag[v].size();j++)
					S.f[loc[v]][flag[v][j]]++;
			}
		}
//		cout<<loc[1]<<" "<<loc[2]<<" "<<loc[3]<<" "<<loc[4]<<" "<<loc[5]<<endl;
	}
}T;

int main(){
//	freopen("CF316G.in","r",stdin);
//	freopen("CF316G.out","w",stdout);
	scanf("%s",s + 1);
	T.insert(s,0);
	l[0] = 1,r[0] = N;
	n = read();
	for(rg int i = 1;i <= n;i++){
		scanf("%s",s + 1);
		l[i] = read(),r[i] = read();
		T.insert(s,i);
	}
	T.build();
	S.solve();
//*****************************************************
//clock_t s = clock();
//while(clock() - s < 1e8);
	return 0;
}