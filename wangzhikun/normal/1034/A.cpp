#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
template<typename T> void read(T &x){
	x = 0;int f = 1;char ch = getchar();
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch = getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch = getchar();}
	x*=f;
}
#define N 15000050
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll n,a[300030];
vector<ll> pr;
ll minn[N+100] = {0};
int cnt[N+100] = {0};
int main(){
	read(n);
	for(int i=0;i<n;i++)read(a[i]);
	ll d = a[0];
	for(int i=0;i<n;i++){
		d = gcd(d,a[i]);
	}
	for(int i=0;i<n;i++){
		a[i]/=d;
	}
	for(ll a=2;a<N;a++){
		if(minn[a] == 0){
			minn[a] = a;
			pr.push_back(a);
		}
		for(ll i = 0;i<pr.size() && pr[i]*a<=N;i++){
			minn[a*pr[i]] = pr[i];
		}
	}
	int ans = 0;
	for(int i=0;i<n;i++){
		int cm = 100000000;
		while(a[i]!=1){
			if(minn[a[i]]!=cm){
				cnt[minn[a[i]]]++;
				ans = max(ans,cnt[minn[a[i]]]);
				cm = minn[a[i]];
			}
			a[i]/=minn[a[i]];
		}
	}
	if(ans == 0){
		cout<<-1<<endl;
	}else{
		cout<<n-ans<<endl;
	}
	
	return 0;
}