#include<bits/stdc++.h>
#define N 100005

int T;

int n;

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		std::set<int> s;
		for(int i=1;i<=n;i++){
			int x;
			scanf("%d",&x);
			s.insert(x);
		}
		bool flg=1;
		for(auto x:s)
			if(s.count(x+1))
				flg=0;
		puts(flg||!s.count(1)?"Yes":"No");
	}
}