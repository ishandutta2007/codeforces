#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <iomanip>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define debug(x) cerr<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long ll;
typedef pair<ll,double> pid;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();ll f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}
const int SZ = 6000020;
map<int,int> ops;
map<int,int>::iterator it;
int n;

bool ilazy[SZ] = {0};
int ls[SZ],rs[SZ],pooln = 2;
ll su[SZ],mi[SZ],lazy[SZ];

void zd(int id,int l,int r){
	if(ilazy[id]){
		su[id] = lazy[id]*(r-l+1);
		mi[id] = min(0ll,su[id]);
	}
}

void pushd(int id,int l,int r){
	if(ilazy[id]){
		if(!ls[id]) ls[id] = pooln++;
		if(!rs[id]) rs[id] = pooln++;
		ilazy[ls[id]] = ilazy[rs[id]] = 1;
		lazy[ls[id]] = lazy[rs[id]]  = lazy[id];
		su[id] = lazy[id]*(r-l+1);
		mi[id] = min(0ll,su[id]);
		lazy[id] = 0;ilazy[id] = 0;
	}
}

void qset(int id,int l,int r,int ql,int qr,ll v){
	//if(id == 1)cout<<"QSET "<<id<<' '<<l<<' '<<r<<' '<<ql<<' '<<qr<<' '<<v<<endl;
	if(ql <=l && r <=qr){
		ilazy[id] = 1;
		lazy[id] = v;
		zd(id,l,r);
		return;
	}
	pushd(id,l,r);
	int mid = (l+r)>>1;
	if(ql<=mid){
		if(!ls[id]) ls[id] = pooln++;
		qset(ls[id],l,mid,ql,qr,v);
	}
	if(qr>mid){
		if(!rs[id]) rs[id] = pooln++;
		qset(rs[id],mid+1,r,ql,qr,v);
	}
	zd(ls[id],l,mid);
	zd(rs[id],mid+1,r);
	su[id] = su[ls[id]]+su[rs[id]];
	mi[id] = min(mi[ls[id]],su[ls[id]]+mi[rs[id]]);
}

pid que(int id,int l,int r,int ql,ll v){
//	cout<<id<<' '<<l<<' '<<r<<' '<<ql<<' '<<v<<endl;
	if(l == r){
		if(su[id]+v<=0 || v<=0){
			//cout<<"RET"<<su[id]<<' '<<(double)l-(double)v/su[id]<<endl;
			return make_pair(su[id],(double)l-(double)v/su[id]);
		}else{
			return make_pair(su[id],-1.0);
		}
	}
//	cout<<su[id]<<' '<<mi[id]<<' '<<lazy[id]<<endl;
	pushd(id,l,r);
	int mid = (l+r)>>1;
	zd(ls[id],l,mid);
	zd(rs[id],mid+1,r);
	if(ql<=l){
		if(mi[ls[id]]+v<=0){
			pid cret = que(ls[id],l,mid,ql,v);
			cret.first+=su[rs[id]];
			return cret;
		}else{
			if(su[ls[id]]+mi[rs[id]] +v <=0){
//				cout<<su[ls[id]]<<endl;
				pid lret = que(rs[id],mid+1,r,ql,v+su[ls[id]]);
				lret.first+=su[ls[id]];
				return lret;
			}else{
				return make_pair(su[id],-1.0);
			}
		}
	}
	if(ql<=mid){
		pid lret = que(ls[id],l,mid,ql,v);
		if(lret.second>=0){
			lret.first+=su[rs[id]];
			return lret;
		}
		pid rret = que(rs[id],mid+1,r,ql,v+lret.first);
		rret.first+=lret.first;
		return rret;
	}else{
		pid cret =  que(rs[id],mid+1,r,ql,v);
		return cret;
	}
	zd(ls[id],l,mid);
	zd(rs[id],mid+1,r);
	su[id] = su[ls[id]]+su[rs[id]];
	mi[id] = min(mi[ls[id]],su[ls[id]]+mi[rs[id]]);
}

int q,op;
int main() {
	cout<<setprecision(15)<<fixed;
	ops[-1] = 0;
	ops[1<<30] = 0;
	read(q);
	while(q--){
		read(op);
		if(op == 1){
			ll t,s;
			read(t);read(s);
			it = ops.lower_bound(t);
			qset(1,0,1<<30,t,it->first-1,s);
			ops[t] = s;
		}
		if(op == 2){
			ll t;
			read(t);
			ops.erase(t);
			it = ops.lower_bound(t);
			int cr = it->first-1;
			it--;
			qset(1,0,1<<30,it->first,cr,it->second);
		}
		if(op == 3){
			ll l,r,v;
			
			read(l);read(r);read(v);
			if(v == 0){
				cout<<l<<endl;
				continue;
			}
			it = ops.lower_bound(l);
		//	cout<<it->first<<endl;
			pid cret = que(1,0,1<<30,it->first,v);
			if(cret.second>r){
				cout<<-1<<endl;
			}else{
				cout<<cret.second<<endl;
			}
		}
	}
	return 0;
}

/*
100000
1 830145503 -4
1 306450984 -7
1 265142137 -5
1 745314149 -5
1 667144581 3
1 193212182 -5
3 714500219 918923184 49
3 577035379 937453937 49
*/