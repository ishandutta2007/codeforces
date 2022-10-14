// Author : WangZhikun
// Date   : 2018.08.16
#include <set>
#include <cmath>
#include <queue>
#include <ctime>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define popcnt __builtin_popcount
using namespace std;
typedef long long ll;
template<typename T> void read(T &x){
	x = 0;ll f = 1;char ch = getchar();
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch = getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch = getchar();}x*=f;
}
int n,m,a[200020],flg = 1,lp[200020] = {0},rp[200020] = {0},vv[2000080] = {0};
void tset(int id,int cl,int cr,int p,int v){
	if(cl == cr){
		vv[id] = v;
		return;
	}
	int mid = (cl+cr)/2;
	if(p<=mid) tset(id*2,cl,mid,p,v);
	else tset(id*2+1,mid+1,cr,p,v);
	vv[id] = min(vv[id*2],vv[id*2+1]);
}
int tget(int id,int cl,int cr,int l,int r){
	if(cl == l && cr == r) return vv[id];
	int mid = (cl+cr)/2;
	if(r<=mid) return tget(id*2,cl,mid,l,r);
	if(l>mid) return tget(id*2+1,mid+1,cr,l,r);
	return min(tget(id*2,cl,mid,l,mid),tget(id*2+1,mid+1,cr,mid+1,r));
}
int main(){
	cin>>n>>m;
	for(int i=0;i<=m;i++){
		lp[i] = 200021;
		rp[i] = -1;
	}
	for(int i=0;i<n;i++){
		read(a[i]);
		if(a[i] == m)flg = 0;
	}
	if(flg){
		for(int i=0;i<n;i++){
			if(a[i] == 0){
				a[i] = m;
				flg = 0;
				break;
			}
		}
		if(flg){
			cout<<"NO"<<endl;
			return 0;
		}
	}
	for(int i=0;i<n;i++){
		int cm = 0;
		if(a[i] == 0){
			if(i)cm = a[i-1];
			for(int j=i+1;j<n;j++)if(a[j]){
				cm = max(cm,a[j]);
				break;
			}
			for(int j=i;j<n;j++){
				if(!a[j]) a[j] = cm;
				else break;
			}
		}
	}
	int ans = 1;
	for(int i=0;i<n;i++){
		tset(1,0,200020,i,a[i]);
		lp[a[i]] = min(lp[a[i]],i);
		rp[a[i]] = max(rp[a[i]],i);
	}
	for(int i=1;i<=m;i++){
		if(rp[i]>=lp[i]){
			if(tget(1,0,200020,lp[i],rp[i])<i) ans = 0;
		}
	}
	if(ans){
		cout<<"YES"<<endl;
		for(int i=0;i<n;i++)cout<<a[i]<<' ';
		cout<<endl;
	}else{
		cout<<"NO"<<endl;
	}
	return 0;
}