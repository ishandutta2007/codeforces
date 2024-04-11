// author: xay5421
// created: Sun May 30 23:00:07 2021
#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int N=100005;
int T,n;
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		vector<int>v;
		rep(i,1,n){
			int x;
			scanf("%d",&x);
			if(x==1){
				v.push_back(1);
			}else{
				while(v.back()!=x-1)v.pop_back();
				v.back()=x;
			}
			rep(i,0,SZ(v)-1)printf("%d%c",v[i],i==SZ(v)-1?'\n':'.');
		}
	}
	return 0;
}