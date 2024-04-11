#include <bits/stdc++.h>

using namespace std;

// Prioridade

typedef long long   ll;
#define int ll
typedef pair<ll,ll> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpi;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for(int i = a; i < (int)(b); i++)
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define all(x) x.begin(),x.end()
#define MOD 1000000007
#define endl '\n'
#define mdc(a, b) (__gcd((a), (b)))
#define mmc(a, b) (((a)/__gcd(a, b)) * b)
#define W(x) cerr << "\033[31m"<<  #x << " = " << x << "\033[0m" << endl;
// fim da Prioridade

#define MAXN 200005
int ans[4*MAXN + 1];
int arr[4*MAXN + 1];
int delta[4*MAXN + 1];
void update(int node){
	ans[node] = min(min(ans[node<<1] , delta[node<<1]),min( ans[(node<<1) + 1] , delta[(node<<1) + 1]));
}
void lazy(int node){
	delta[node<<1] = min(delta[node],delta[node<<1]);
	delta[(node<<1)+1] = min(delta[node], delta[(node<<1)+1]);
	delta[node] = INF; 
}
void build(int node, int left, int right){
	if(left == right){
		ans[node] = INF;
		return;
	}
	int m = (left + right) >> 1;
	build(node<<1,left,m);
	build((node<<1) + 1,m+1,right);
	update(node);
	//!@CAMPUSufc#nmtil!@
}
void modify(int node, int left,int right, int a, int b, int val){
	if(b < left || right < a){
		return;
	}
	if(a <= left && right <= b){
		delta[node] = min(delta[node],val);
		return;
	}
	if(left != right){
		lazy(node);
	}else{
		return;
	}
	int m = (left + right) >> 1;
	modify(node << 1, left,m,a,b,val);
	modify((node << 1)+1, m+1,right,a,b,val);
	update(node);
}
ll query(int node,int left,int right,int a, int b){
	if(b < left || right < a){
		return INFLL;
	}
	if(a <= left && right <= b){
		if(left != right){
			lazy(node);
			update(node);
		}
		return min(ans[node], delta[node]);
	}
	if(left != right){
		lazy(node);
	}else{
		return min(ans[node], delta[node]);
	}
	int m = (left + right) >> 1;
	ll esq = query(node << 1, left,m,a,b);
	ll dir = query((node << 1)+1, m+1,right,a,b);
	update(node);
	return min(esq,dir);
}
int32_t main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	memset(delta,0x3f,sizeof delta);
	int n, m;
	cin >> n >> m;
	vector<pair<int,ll> > frogs(n);
	vector<pair<int,ll> > order(n);
	REP(i,0,n){
		cin >> frogs[i].F >> frogs[i].S;
		order[i] = frogs[i]; 
	}
	vector<pair<int,ll> > bugs(m);
	vll compre;
	vll pos(n);
	vll eaten(n,0);
	REP(i,0,m){
		cin >> bugs[i].F >> bugs[i].S;
		compre.PB(bugs[i].F);
	}
	sort(all(order));
	sort(all(compre));
	compre.erase(unique(all(compre)),compre.end());
	int tam = compre.size();
	build(1,0,tam);
	REP(i,0,n){
		int start = lower_bound(all(compre),frogs[i].F) - compre.begin();
		int end = upper_bound(all(compre),frogs[i].F + frogs[i].S) - compre.begin();
		int ordenado = lower_bound(all(order),frogs[i]) - order.begin();
		pos[ordenado] = i;
		modify(1,0,tam,start,end-1,ordenado);
	}
	map<int,ll> remain;
	map<int,ll> hehe;
	REP(i,0,m){
		int location = lower_bound(all(compre),bugs[i].F) - compre.begin();
		int ans = query(1,0,tam,location,location);
		if(ans == INF){
	//		W("INF");
			remain[bugs[i].F] += bugs[i].S;
			hehe[bugs[i].F]++;
		}else{
			int sapo = pos[ans];
		//	W(sapo);
			//W(i);
			frogs[sapo].S += bugs[i].S;
		//	W(frogs[sapo].S);
			eaten[sapo]++;
			int start = lower_bound(all(compre),frogs[sapo].F) - compre.begin();
			int end = upper_bound(all(compre),frogs[sapo].F + frogs[sapo].S) - compre.begin();
			int ordenado = ans;
			modify(1,0,tam,start,end-1,ordenado);
			while(1){
				auto died = remain.lower_bound(frogs[sapo].F);
				
				if(died == remain.end()){
					break;
				}
				if(died->F < frogs[sapo].F)
					break;
				if(died->F > frogs[sapo].S + frogs[sapo].F){
					break;
				}
				//W(died->F);
			//	W(died->S);
				frogs[sapo].S += died->S;
				eaten[sapo] += hehe[died->F];
				hehe.erase(died->F);
				end = upper_bound(all(compre),frogs[sapo].F + frogs[sapo].S) - compre.begin();
				remain.erase(died);
				modify(1,0,tam,start,end-1,ordenado);
			}
		}
	}
	REP(i,0,n){
		cout << eaten[i] << " " << frogs[i].S << endl;
	}
	
	return 0;
}