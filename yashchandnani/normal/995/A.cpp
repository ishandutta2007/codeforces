#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;


#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

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
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void pre(){


}

void solve(){


}
int pos[209],dest[209];
int n,k,fns;
int car[209];
int a[20009],b[20009],c[20009];
int v[209];
void put(int x){
	fns++;
	if(pos[x]>=n){
		a[fns] = x;b[fns]=4;c[fns]=pos[x]-n+1;
	}
	else{
		a[fns] = x;b[fns]=1;c[fns]=pos[x]+1;
	}
	car[pos[x]] = 0;
	v[x] = 1;
}
int cur;
void swp(){
	int x,nt;
	if(cur==0){
		nt=n;
	}
	else if(cur==2*n-1){
		nt=n-1;
	}
	else if(cur<n){
		nt=cur-1;
	}
	else{
		nt=cur+1;
	}
	x = car[nt];
	if(x==0) {
		cur=nt;
		return;
	}
	pos[x] = cur;
	car[nt] = 0;
	car[cur] = x;
	cur = nt;
	fns++;
	if(pos[x]>=n){
		a[fns] = x;b[fns]=3;c[fns]=pos[x]-n+1;
	}
	else{
		a[fns] = x;b[fns]=2;c[fns]=pos[x]+1;
	}
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	cin>>n>>k;
	cur=-1;
	rep(i,n){
		int x;cin>>x;
		if(x!=0) dest[x] = i;
	}
	rep(i,n){
		int x;cin>>x;
		if(x!=0) pos[x] = i,car[i]=x;
		else cur = i;
	}
	rep(i,n){
		int x;cin>>x;
		if(x!=0) pos[x] = i+n,car[i+n]=x;
		else cur=i+n;
	}
	rep(i,n){
		int x;cin>>x;
		if(x!=0) dest[x] = i+n;
	}
	repA(i,1,k) if(pos[i]==dest[i]) cur=pos[i];
	if(cur==-1){
		cout<<-1;
		return 0;
	}
	else{
		int ll = 0;
		repA(i,1,k) if(pos[i]==dest[i]&&v[i]==0) put(i),ll++;
		while(ll!=k) {
			swp();
			repA(i,1,k) if(pos[i]==dest[i]&&v[i]==0) put(i),ll++;
		}
	}
	cout<<fns<<'\n';
	repA(i,1,fns){
		cout<<a[i]<<' '<<b[i]<<' '<<c[i]<<'\n';
	}
	return 0;
}