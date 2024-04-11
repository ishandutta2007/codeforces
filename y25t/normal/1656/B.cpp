#include<bits/stdc++.h>
#define N 100005

int T;

int n,k;

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		std::set<int> s;
		for(int i=1;i<=n;i++){
			int x;
			scanf("%d",&x);
			s.insert(x);
		}
		bool flg=0;
		for(auto x:s)
			if(s.count(x+k))
				flg=1;
		puts(flg?"Yes":"No");
	}
}