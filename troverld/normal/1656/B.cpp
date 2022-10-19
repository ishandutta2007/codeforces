#include<bits/stdc++.h>
using namespace std;
int T,n,m;
set<int>s;
int main(){
	scanf("%d",&T);
	while(T--){
		bool ok=false;
		scanf("%d%d",&n,&m);
		for(int i=1,x;i<=n;i++)scanf("%d",&x),s.insert(x);
		for(auto x:s)if(s.find(x+m)!=s.end())ok=true;
		s.clear();
		puts(ok?"Yes":"No");
	}
	return 0;
}