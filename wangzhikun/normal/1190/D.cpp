//determined
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <complex>
#include <cassert>
#include <iostream>
#include <algorithm>
#define set0(x) memset(x,0,sizeof(x))
#define debug(x) cerr<<#x<<'='<<x<<endl
using namespace std;
typedef long long ll;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();int f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();};
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}
	x*=f;
}

int n,m1,m2,x[200020],y[200020],a[200020],b[200020],cnt[200020],szsz[200020];

void add(int p,int num){
	while(p<200020){
		szsz[p]+=num;
		p+=p&(-p);
	}
}
int query(int p){
	int ret = 0;
	while(p){
		ret+=szsz[p];
		p-=p&(-p);
	}
	return ret;
}

vector<int> G[200020];

int main(){
	read(n);
	for(int i=0;i<n;i++){
		read(x[i]);read(y[i]);
		a[i] = x[i];b[i] = y[i];
	}
	sort(a,a+n);
	m1 = unique(a,a+n)-a;
	sort(b,b+n);
	m2 = unique(b,b+n)-b;
	
	for(int i=0;i<n;i++){
		x[i] = lower_bound(a,a+m1,x[i])-a+5;
		y[i] = lower_bound(b,b+m2,y[i])-b+5;
		cnt[x[i]]+=1;
		if(cnt[x[i]] == 1){
			add(x[i],1);
		}
		G[y[i]].push_back(x[i]);
	}
	ll ans = 0;
	for(int i=0;i<200020;i++){
		sort(G[i].begin(),G[i].end());
		int lp = 1;
		for(auto ct:G[i]){
			ans = ans+1ll*(query(200015)-query(ct-1))*(query(ct)-query(lp));
			lp = ct;
		}
		for(auto ct:G[i]){
			cnt[ct]-=1;
			if(cnt[ct] == 0)add(ct,-1);
		}
	}
	
	
	cout<<ans<<endl;
	return 0;
}