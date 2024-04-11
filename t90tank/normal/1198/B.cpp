#include <bits/stdc++.h>
using namespace std; 
using ll = long long; 
using pii = pair<int,int>; 
using db = double; 
using vi = vector<int>; 
using vl = vector<ll>; 
#define fir first
#define sec second
#define pb push_back
#define lowbit(x) ((x)&(-(x))) 

const int maxn = 400006; 

set<pii> S; 
int n, q; 
int a[maxn];
int f[maxn]; 

int getf(int v) {
	return f[v]==v?v:(f[v]=getf(f[v])); 
}

int main() {
	ios::sync_with_stdio(false); 
	cin>>n; 
	for (int i = 1; i <= n; ++i) {
		cin>>a[i]; f[i] = i; 
		S.insert({a[i],i}); 
	}
	cin>>q; 
	for (int i = 1; i <= q; ++i) {
		f[n+i] = n+i; 
		int t,p,x; 
		cin>>t; 
		if (t == 1) { 
			cin>>p>>x;
			f[p] = n+i; a[n+i] = x;  
			S.insert({a[n+i],n+i}); 
		}
		else {
			cin>>x; 
			a[n+i] = x; 
			S.insert({a[n+i],n+i}); 
			while (S.begin()->fir < x) {
				auto p = *S.begin(); 
				if (f[p.sec] == p.sec) 
					f[p.sec] = n+i; 
				S.erase(p); 
			}
		}
		/*
		for (auto p : S) {
			cout<<p.fir<<' '<<p.sec<<endl; 
		}
		puts( "-----" ); 
		*/
	}
	//cout<<getf(2)<<endl; 
	for (int i = 1; i <= n; ++i) cout<<a[getf(i)]<<' '; 
	puts( "" ); 
}