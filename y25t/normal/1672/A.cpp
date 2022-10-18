#include<bits/stdc++.h>
#define N 55

int T;

int n;

int f[N];

int main(){
	scanf("%d",&T);
	for(int i=2;i<=50;i++){
		std::set<int> s;
		for(int j=1;j<i;j++)
			s.insert(f[j]^f[i-j]);
		while(s.count(f[i]))
			f[i]++;
	}
	while(T--){
		scanf("%d",&n);
		int s=0;
		for(int i=1;i<=n;i++){
			int x;
			scanf("%d",&x);
			s^=f[x];
		}
		puts(s?"errorgorn":"maomao90");
	}
}