#include <bits/stdc++.h>
 
#define debug(x) cerr<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();ll f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}
struct fenwick_tree{
	int c[300030];
	void addseg(int l,int r,int v){
		if(r<l)return;
		ad2(l,v);
		ad2(r+1,-v);
	}
	inline void ad2(int x, int y){
		x+=1;
		while (x <= 300010){
			c[x]+=y;
			x += x & -x;
		}
	}
	inline int sum(int x){
		x+=1;
		int res = 0;
		while (x > 0){
			res +=c[x];
			x -= x & -x;
		}
		return res;
	}
}A,B;
 
vector<int> V[300030];
int n,m,a[300030],loc[300030] = {0},ansl[300030],ansr[300030];
 
int main() {
	read(n);read(m);
	for(int i=1;i<=m;i++){
		read(a[i]);
		if(loc[a[i]] == 0){
			
			ansr[a[i]] = a[i]+B.sum(a[i]);
			B.addseg(1,a[i],1);
		}else{
			ansr[a[i]] = max(ansr[a[i]],1+A.sum(loc[a[i]]));
		}
		A.addseg(loc[a[i]]+1,i-1,1);
		loc[a[i]] = i;
		V[a[i]].push_back(i);
	}
	for(int i=1;i<=n;i++){
		if(loc[i]){
			//cout<<' '<<i<<' '<<loc[i]<<' '<<A.sum(loc[i])<<endl;
			ansr[i] = max(ansr[i],1+A.sum(loc[i]));
		}
	}
	int cnt = 0;
	for(int i=n;i>=1;i--){
		if(V[i].empty()){
			ansl[i] = i;
			ansr[i] = i+cnt;
			continue;
		}
		cnt+=1;
		ansl[i] = 1;
	}
	for(int i=1;i<=n;i++){
		cout<<ansl[i]<<' '<<ansr[i]<<endl;
	}
	return 0;
}