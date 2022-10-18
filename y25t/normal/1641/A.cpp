#include<bits/stdc++.h>

int T;

int n,x;

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&x);
		std::multiset<int> s;
		for(int i=1;i<=n;i++){
			int a;
			scanf("%d",&a);
			s.insert(a);
		}
		int ans=0;
		while(s.size()){
			int u=*s.rbegin();
			s.erase(s.find(u));
			if(u%x==0&&s.count(u/x))
				s.erase(s.find(u/x));
			else
				ans++;
		}
		printf("%d\n",ans);
	}
}