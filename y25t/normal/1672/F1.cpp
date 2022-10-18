#include<bits/stdc++.h>
#define N 200005

int T;

int n,a[N],b[N];

std::vector<int> V[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		std::set<int> s;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),V[a[i]].push_back(i),s.insert(a[i]);
		while(s.size()){
			int y=*s.rbegin();
			for(auto x:s){
				b[V[x].back()]=y,V[x].pop_back();
				if(x==*s.rbegin())
					break;
				y=x;
			}
			std::set<int> t;
			for(auto x:s)
				if(V[x].size())
					t.insert(x);
			std::swap(s,t);
		}
		for(int i=1;i<=n;i++)
			printf("%d ",b[i]);
		puts("");
	}
}