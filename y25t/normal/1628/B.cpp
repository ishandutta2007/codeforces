#include<bits/stdc++.h>
#define N 200005

int T;

int n;
std::string a[N];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		std::set<std::string> s,S;
		for(int i=1;i<=n;i++)
			std::cin>>a[i];
		bool flg=0;
		for(int i=n;i;i--){
			auto t=a[i];
			std::reverse(t.begin(),t.end()),s.insert(t);
			if(a[i].size()==3){
				std::string b;
				b+=a[i][2],b+=a[i][1];
				S.insert(b);
			}
			if(s.count(a[i])||S.count(a[i]))
				flg=1;
			if(a[i].size()==3){
				std::string b;
				b+=a[i][0],b+=a[i][1];
				if(s.count(b))
					flg=1;
			}
		}
		puts(flg?"YES":"NO");
	}
}