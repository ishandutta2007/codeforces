#include<bits/stdc++.h>
#define ll long long
#define N 200005

int T;

int n;

int main(){
	scanf("%d",&T);
	while(T--){
		std::multiset<ll> s,t;
		scanf("%d",&n);
		ll sum=0;
		for(int i=1;i<=n;i++){
			int x;
			scanf("%d",&x);
			s.insert(x);
			sum+=x;
		}
		t.insert(sum);
		bool flg=1;
		while(t.size()){
			ll x=*t.begin();
			t.erase(t.find(x));
			if(s.count(x)){
				s.erase(s.find(x));
				continue;
			}
			if(x==1){
				flg=0;
				break;
			}
			t.insert(x>>1),t.insert((x+1)>>1);
		}
		puts(flg?"YES":"NO");
	}
}