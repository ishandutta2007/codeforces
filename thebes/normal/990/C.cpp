#include <bits/stdc++.h>
using namespace std;

int N, a, b, x, i; string s;
map<int,int> pre, suf;
long long ans;

int main(){
	for(scanf("%d",&N),i=1;i<=N;i++){
		cin >> s; a = b = 0;
		for(char c : s){
			if(c=='(') a++;
			else{
				if(a) a--;
				else b++;
			}
		}
		if(a==0&&pre.count(b)) ans+=pre[b];
		if(b==0&&suf.count(a)) ans+=suf[a];
		if(a==0&&b==0) ans++;
		if(a==0) suf[b]++;
		if(b==0) pre[a]++;
	}
	printf("%lld\n",ans);
	return 0;
}