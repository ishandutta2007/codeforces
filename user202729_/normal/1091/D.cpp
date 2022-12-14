#include<iostream>

int constexpr MOD=998244353;

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;
	int a1=1,a2=1;
	for(int i=2;i<=n;++i){
		a1=a1*(int64_t)i%MOD;
		a2=(a2+1LL)*i%MOD;
	}
	std::cout<<(a1*(n+1LL)+MOD-a2)%MOD<<'\n';
}