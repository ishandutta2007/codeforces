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
priority_queue<int> q;
int se(){
	int x = q.top();
	q.pop();
	int y = q.top();
	q.push(x);
	return y;
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int n;cin>>n;
	int ans[n+1] = {0};
	if(n==1) {cout<<1; return 0;}
	else if(n==2) {cout<<1; return 0;}
	int best_ans = -1,best_idx=1;
	int x;cin>>x;ans[x]--;
	q.push(x);
	cin>>x;
	if(x<q.top()) ans[q.top()]++;
	else if (x>q.top()) {ans[x]--;}
	q.push(x);
	rep(i,n-2){
		cin>>x;
		if(x<q.top()&&x>se()) ans[q.top()]++;
	else if (x>q.top()) {ans[x]--;}
		q.push(x);
	}
	repA(i,1,n){
		if(ans[i]>best_ans) {
			best_ans = ans[i];
			best_idx = i;
		}
	}
	cout<<best_idx;
	return 0;
}