#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
typedef long long LL;
const int N = 1000;
const LL INF = 1e18;
 
const int maxp = 617;
int T, n, m=0, x;
int p[N+5], pr[N+5];
int num[N+5];
LL Q;
 
void factor(int x){
	rep(i,1,m){
		int y = pr[i];
		while(x%y==0){
			num[y]++;
			x /= y;
		}
	}
}
 
LL full(LL x){
	LL res = 1;
	while(res*x<=1e9) res *= x;
	return res;
}
 
int main() {
	rep(i,1,N) p[i] = i;
	rep(i,2,N) if(p[i]==i) {
		pr[++m] = i;
		for(int j=i*i;j<=N;j+=i) p[j] = i;
	}
	
	cin>>T;
	while(T--){
		memset(num,0,sizeof num);
		
		Q = 1;
		rep(i,2,maxp) if(p[i]==i){
			if(INF/i<Q){
				cout<<"? "<<Q<<endl<<flush;
				cin>>x;
				factor(x);
				Q = i;
			}else Q *= i;
		}
		cout<<"? "<<Q<<endl<<flush;
		cin>>x;
		factor(x);
		
		int flag = 0;
		rep(i,2,maxp) if(num[i]) flag++;
		if(!flag){
			cout<<"! 8"<<endl;
			continue;
		}
		
		Q = 1;
		rep(i,1,maxp) if(num[i]) {
			num[i] = 0;
			if(Q>1e9){
				cout<<"? "<<Q<<endl<<flush;
				cin>>x;
				factor(x);
				Q = 1;
			}
			Q *= full(i);
		}
		if(Q>1){
			cout<<"? "<<Q<<endl<<flush;
			cin>>x;
			factor(x);
		}
		
		int ans = 1;
		rep(i,1,maxp) if(num[i]) {
			ans *= (num[i]+1);
		}
		cout<<"! "<<max(ans+7,ans*2)<<endl;
	}
	return 0;
}