#include <bits/stdc++.h>
using namespace std;

const int mod=1e9+7;
int N, ans, a, b, i;
string s, t;

int main(){
	cin >> s >> t >> N; a=1;
	for(i=1;i<=N;i++){
		int c=(1LL*b*(s.size()-1))%mod;
		int d=(1LL*b*(s.size()-2)+a)%mod;
		a = c; b = d;
	}
	for(i=0;i<s.size();i++){
		bool flag = true;
		for(int j=0;j<t.size();j++)
			if(s[(i+j)%s.size()]!=t[j]) flag=false;
		if(flag&&!i) ans=(ans+a)%mod;
		else if(flag) ans=(ans+b)%mod;
	}
	printf("%d\n",ans);
	return 0;
}