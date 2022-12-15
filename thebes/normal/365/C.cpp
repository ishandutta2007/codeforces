#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll A, M, i, j, p[4004], ans;
unordered_map<ll,ll> c;
string s;

int main(){
	cin >> A >> s; M=s.size();
	for(i=0;i<s.size();i++)
		p[i+1]=p[i]+s[i]-'0';
	for(i=1;i<=M;i++){
		for(j=0;j<i;j++)
			c[p[i]-p[j]]++;
	}
	for(i=1;i<=M;i++){
		for(j=0;j<i;j++){
			ll x = p[i]-p[j];
			if(A == 0 && x == 0)
				ans += M*(M+1)/2;
			else if(A == 0)
				ans += c[0];
			else if(x != 0 && A%x==0)
				ans += c[A/x];
		}
	}
	cout << ans;
	return 0;
}