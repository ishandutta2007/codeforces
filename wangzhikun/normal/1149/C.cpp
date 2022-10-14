#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();int f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}

const int N = 200010;
int n,q,inf = 1e9;
char s[N];
struct node{
	// max a-2b+c
	// a,-2b,ab,bc,abc
	int val[5],csu;
}T[N*4];

void upd(int p,int l,int r,int req){
	if(l == r){
		T[p].csu = -1+(s[l] == '(')*2;
		T[p].val[0] = T[p].csu;
		T[p].val[1] = -2*T[p].csu;
		T[p].val[2] = T[p].val[3] = -T[p].csu;
		T[p].val[4] = 0;
		return;
	}
	int mid = (l+r)/2;
	if(req<=mid || req == -1)upd(p*2,l,mid,req);
	if(req>mid  || req == -1)upd(p*2+1,mid+1,r,req);
	T[p].csu = T[p*2].csu+T[p*2+1].csu;
	T[p].val[0] = max(T[p*2].val[0],T[p*2+1].val[0]+T[p*2].csu);
	T[p].val[1] = max(T[p*2].val[1],T[p*2+1].val[1]-2*T[p*2].csu);
	T[p].val[2] = max(T[p*2].val[2],T[p*2+1].val[2]-T[p*2].csu);
	T[p].val[3] = max(T[p*2].val[3],T[p*2+1].val[3]-T[p*2].csu);
	T[p].val[4] = max(T[p*2].val[4],T[p*2+1].val[4]);
	T[p].val[2] = max(T[p].val[2],T[p*2].val[0]+T[p*2+1].val[1]-2*T[p*2].csu);
	T[p].val[3] = max(T[p].val[3],T[p*2].val[1]+T[p*2+1].val[0]+T[p*2].csu);
	T[p].val[4] = max(T[p].val[4],T[p*2].val[0]+T[p*2+1].val[3]-T[p*2].csu);
	T[p].val[4] = max(T[p].val[4],T[p*2].val[2]+T[p*2+1].val[0]+T[p*2].csu);
}

int main() {
	cin>>n>>q;
	cin>>s;
	upd(1,0,n*2-3,-1);
	cout<<T[1].val[4]<<endl;
	for(int i=0;i<q;i++){
		int l,r;
		cin>>l>>r;
		l--;r--;
		if(r<l)swap(l,r);
		swap(s[l],s[r]);
		upd(1,0,n*2-3,l);
		upd(1,0,n*2-3,r);
		cout<<T[1].val[4]<<endl;
	}
	return 0;
}