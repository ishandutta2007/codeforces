#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;
const double eps = 1e-9;
typedef long long ll;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

char s[MAXN];
PII a[MAXN];
vector<PII> E[MAXN];
int deg[MAXN];
int n, m;
int vis[MAXN];

int work(int p){
	for(int i = 1; i <= n; i++)
		deg[i] = 0;
	for(int i = 1; i <= p; i++){
		deg[a[i].second]++;
	}

/*	cout<<"#### "<<p<<endl;
		for(int i = 1; i <= n; i++)
			cout<<deg[i]<<' ';  cout<<endl;
*/
	queue<int> Q;
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		vis[i] = 0;
		if (deg[i] == 0){
			Q.push(i);
			cnt++;
			vis[i] = 1;
		}
	}
	while(!Q.empty()){
		if (Q.size() > 1)
			return 0;
		int x = Q.front();
	/*	cout<<x<<endl;
		for(int i = 1; i <= n; i++)
			cout<<deg[i]<<' ';cout<<endl;*/
		Q.pop();
		for(int i = 0; i < E[x].size(); i++)
			if (E[x][i].second > p)
				break;
			else{
				if (vis[E[x][i].first])
					continue;
				deg[E[x][i].first]--;
				if (deg[E[x][i].first] == 0){
					vis[E[x][i].first] = 1;
					Q.push(E[x][i].first);
					cnt++;
				}
			}/*
		for(int i = 1; i <= n; i++)
			cout<<deg[i]<<' ';cout<<endl;*/
	}
	if (cnt == n)
		return 1;
	else
		return 0;
}

int main(){
	cin>>n>>m;
	for(int i = 1; i<= n; i++)
		E[i].clear(), deg[i] = 0;
	for(int i = 1; i <= m; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		a[i] = PII(x, y);
		E[x].push_back(PII(y, i));
	//	deg[y] ++;
	}
	int high = m, low = 0, mid;
	if (!work(high)){
		puts("-1");
		return 0;
	}
	while(low + 1 < high){
		mid = (low + high) >> 1;
		if (work(mid))
			high = mid;
		else
			low = mid;
	}
	cout<<high<<endl;
	return 0;
}