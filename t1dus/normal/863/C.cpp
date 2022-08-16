#include <bits/stdc++.h>
using namespace std;

#define L long long
#define F first
#define S second
#define R(i,n) for(int i=0;i<(n);i++)

L W(L x,L y){
	return((x==3 and y==2)or(x==2 and y==1)or(x==1 and y==3));
}

int main() {

	L k,a,b,k1,al[4][4],bo[4][4],x;
	cin >> k1 >> a >> b; k = k1;
	
	R(i,3) R(j,3) cin >> al[i+1][j+1];
	R(i,3) R(j,3) cin >> bo[i+1][j+1];
	vector<pair<L,L> > v;
	set<pair<L,L> > st;
	while(st.find({a,b}) == st.end()){
		v.push_back({a,b});
		st.insert({a,b});
		x = al[a][b];
		b = bo[a][b];
		a = x;	}
	L sz = v.size(),r1,r2,Q=0,C = 0,Q2=0,C2=0;
	R(i,sz){
		if(v[i].F==a and v[i].S==b){
			r1 = i;
			break;
		}
	}
	r2 = sz-1;
	R(i,min(sz,k)){
		if(W(v[i].F,v[i].S)){
			Q++;
			if(i >= r1) C++;
		}
		if(W(v[i].S,v[i].F)){
			Q2++;
			if(i >= r1) C2++;
		}
	}
	k -= min(sz,k);
	if(k!=0){
		L T = k/(r2-r1+1);
		Q += T*C;
		Q2 += T*C2;
		k %= (r2-r1+1);
		R(i,k){
			if(W(v[r1+i].F,v[r1+i].S)){
				Q++;
			}
			if(W(v[r1+i].S,v[r1+i].F)){
				Q2++;
			}
		}

	}
	cout << Q << " " << Q2 << endl;
}