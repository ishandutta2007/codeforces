#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}
}

ll n,r,k,su[500050] = {0},dc[500050] = {0},cc;
ll gmax(ll a,ll b){return a>b?a:b;}
ll gmin(ll a,ll b){return a<b?a:b;}
bool chk(ll x){
	memset(dc,0,sizeof(dc));
	ll cu = 0,cc = 0;
	for(int i=1;i<=n;i++){
		cc+=dc[i];
		if(su[i]+cc < x){
			dc[gmin(i+r+r+1,500020)] = cc-(x-su[i]);
			cu-=cc-(x-su[i]);
			if(cu>k)return 0;
			cc = x-su[i];
		}
	}
	return 1;
}
int main() {
	read(n);read(r);read(k);
	for(int i=1;i<=n;i++){
		read(cc);
		su[gmax(i-r,0)]+=cc;
		su[gmin(i+r+1,500020)]-=cc;
	}
	for(int i=1;i<=n;i++)su[i]+=su[i-1];
	ll l = 0,r = 2e18;
	while(l+1!=r){
		ll mi = (l+r)/2;
		if(chk(mi))l = mi;
		else r = mi;
	}
	cout<<l<<endl;
	return 0;
}