#include <bits/stdc++.h>
using namespace std;

#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fill(a)  memset(a, 0, sizeof (a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int n;
int parent[200009],rnk[200009],mn[200009],mx[200009],s[200009];
void make_set (int v) {
	mn[v] = mx[v] = parent[v] = v;
	rnk[v] = 0;
	s[v] = 1;
}
 
int find_set (int v) {
	if (v == parent[v])
		return v;
	return parent[v] = find_set (parent[v]);
}
 
void union_sets (int a, int b) {
	a = find_set (a);
	b = find_set (b);
	if (a != b) {
		if (rnk[a] < rnk[b])
			swap (a, b);
		parent[b] = a;
		mn[a] = min(mn[a],mn[b]);
		mx[a] = max(mx[a],mx[b]);
		s[a]+=s[b];
		if (rnk[a] == rnk[b])
			++rnk[a];
	}
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>n;
	rep(i,n) make_set(i);
	int a[n];
	bool chk[n]={false};
	rep(i,n) cin>>a[i];
	repA(i,1,n-1){
		if(a[i]==a[i-1]) union_sets(i,i-1);
	}
	priority_queue<pii> q;
	rep(i,n){
		int j = find_set(i);
		if(!chk[j]){
			q.push(mp(s[j],n-j));
			chk[j] = true;
		}
	}
	int ans =0;
	while(!q.empty()){
		pii z = q.top();q.pop();
		z.snd=n-z.snd;
		if(!chk[z.snd]) continue;
		chk[z.snd] = false;
		if(mx[z.snd]!=n-1){
			int ff = find_set(mx[z.snd]+1);
			mn[ff] = mn[z.snd];
		}
		if(mn[z.snd]!=0){
			int ff = find_set(mn[z.snd]-1);
			mx[ff] = mx[z.snd];
		}
		ans++;
		if(mn[z.snd]!=0&&mx[z.snd]!=n-1){
			int c = mn[z.snd]-1;
			int b = mx[z.snd]+1;
			c = find_set(c);b=find_set(b);
			if(a[c]==a[b]){
				chk[c] = false;
				chk[b] = false;
				union_sets(b,c);
				b = find_set(b);
				chk[b] = true;
				q.push(mp(s[b],n-b));
			}
		}
	}
	cout<<ans;
	return 0;
}