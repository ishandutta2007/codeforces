#include <bits/stdc++.h>
#define al(x) (x).begin(),(x).end()
#define gc(x) cin.get(x)
#define gl(x) getline(cin,x)
#define lb(x) ((x)&(-x))
#define sz(x) (int)(x.size())
#define sp ' '
#define nl '\n'
#define fi first
#define se second
using namespace std;
template<class...A>void sc(A&...a){((cin>>a),...);}
template<class...A>void pr(A...a){((cout<<a),...);}
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
typedef pair<int,int> pi;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define int ll

//triangular number
int f(int x){
	int sum=0,i=0;
	while(sum<x){
		i++;sum+=i;
	}
	if(sum==x)return i+1;
	else return -1;
}

int a[2][2];

void die(){
	pr("Impossible\n");
	exit(0);
}

void sol(int ct0,int ct1){
	//pr("sol ",ct0,sp,ct1,nl);
	if(a[0][1]+a[1][0]!=ct0*ct1)return;
	deque<char> ans;
	for(int i=0;i<ct0;i++)ans.push_back('0');
	int bg=0;//where do zeroes begin?
	for(int i=0;i<ct1-1;i++){
		if(a[1][0]-ct0>=0)a[1][0]-=ct0,ans.push_front('1'),bg++;
		else if(a[0][1]-ct0>=0)a[0][1]-=ct0,ans.push_back('1');
	}
	if(ct1)ans.insert(ans.begin()+bg+a[0][1],'1');
	for(char c:ans)pr(c);
	pr(nl);
	exit(0);
}

signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	sc(a[0][0],a[0][1],a[1][0],a[1][1]);
	int ct0=f(a[0][0]),ct1=f(a[1][1]);
	if(ct0==-1||ct1==-1)die();
	//if a[0][0]=0, ct0 could be 0 or 1???
	vector<int> v0={ct0},v1={ct1};
	if(ct0==1)v0.push_back(0);
	else if(ct1==1)v1.push_back(0);
	for(int i:v0){
		for(int j:v1){
			sol(i,j);
		}
	}
	die();
}