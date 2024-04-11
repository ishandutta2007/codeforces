#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
set<int> S;
priority_queue<int> Q1,Q2;
int n,Q;
void insert(int x){
	auto nxt=S.lower_bound(x);
	auto pre=nxt;
	if (nxt!=S.end()) Q1.push(*nxt-x);
	if (pre!=S.begin()){
		--pre;
		Q1.push(x-*pre);
		if (nxt!=S.end())
			Q2.push(*nxt-*pre);
	}
	S.insert(x);
}
void erase(int x){
	S.erase(x);
	auto nxt=S.lower_bound(x);
	auto pre=nxt;
	if (nxt!=S.end()) Q2.push(*nxt-x);
	if (pre!=S.begin()){
		--pre;
		Q2.push(x-*pre);
		if (nxt!=S.end())
			Q1.push(*nxt-*pre);
	}
}
int RES(){
	if (!S.size()) return 0;
	int ans=*S.rbegin()-*S.begin();
	for (;Q2.size()&&Q2.top()==Q1.top();Q1.pop(),Q2.pop());
	return ans-Q1.top();
}
int main(){
	scanf("%d%d",&n,&Q);
	For(i,1,n){
		int x;
		scanf("%d",&x);
		insert(x);
	}
	Q1.push(0);
	cout<<RES()<<endl;
	while (Q--){
		int x,y;
		scanf("%d%d",&x,&y);
		if (x==0) erase(y);
		else insert(y);
		cout<<RES()<<endl;
	}
}