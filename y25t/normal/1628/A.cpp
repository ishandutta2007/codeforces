#include<bits/stdc++.h>
#define N 200005

int T;

int n,a[N];

int b[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		std::set<int> s;
		for(int i=n,t=0;i;i--){
			s.insert(a[i]);
			while(s.count(t))
				t++;
			b[i]=t;
		}
		std::vector<int> ans;
		int l=1;
		while(l<=n){
			int r=0;
			s.clear();
			for(int i=l,t=0;i<=n;i++){
				s.insert(a[i]);
				while(s.count(t))
					t++;
				if(t==b[l]){
					r=i;
					break;
				}
			}
			ans.push_back(b[l]);
			l=r+1;
		}
		printf("%d\n",(int)ans.size());
		for(auto x:ans)
			printf("%d ",x);
		puts("");
	}
}