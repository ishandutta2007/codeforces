#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=305;
int n;
vector<vector<int> >ans;
void ps(vector<int>v){
	ans.pb(v);
}
void sol(int n){
	if(n==3){
		ps({1,2,3});
		ps({1,2,3});
		return;
	}
	if(n==4){
		ps({1,2,3});
		ps({1,2,4});
		ps({3,4,1});
		ps({3,4,2});
		return;
	}
	sol(n-2);
	if(n&1){
		ps({n,n-1,1});
		ps({n,n-1,1});
		for(int i=3;i<n;i+=2){
			ps({n,i,n-1,i-1});
			ps({n,i,n-1,i-1});
		}
	}else{
		ps({n,n-1,1});
		ps({n,n-1,2});
		ps({n,1,n-1,2});
		for(int i=4;i<n;i+=2){
			ps({n,i-1,n-1,i});
			ps({n,i-1,n-1,i});
		}
	}
}
int main(){
	scanf("%d",&n);
	sol(n);
	printf("%d\n",SZ(ans));
	for(auto&v:ans){
		printf("%d\n",SZ(v));
		for(auto&x:v)printf("%d ",x);
		puts("");
	}
	return 0;
}