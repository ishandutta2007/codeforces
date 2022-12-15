#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define F first
#define S second

const int MN = 1e5+5, mod = 1e9+7;
int N, i, j, pw[MN], ps[MN], arr[MN], acc, ans;
string s;

int main(){
	cin >> s;
	N = (int)s.size();
	for(i=0;i<N;i++)
		arr[i+1] = s[i]-'0';
	pw[0] = ps[0] = 1;
	for(i=1;i<=N;i++){
		pw[i] = 10LL*pw[i-1]%mod;
		ps[i] = (ps[i-1]+pw[i])%mod;
	}
	for(i=1;i<N;i++){
		acc = (10LL*acc+arr[i])%mod;
		ans = (ans+1LL*acc*ps[N-i-1])%mod;
	}
	acc = 0;
	for(i=N;i>1;i--){
		acc = (acc+1LL*pw[N-i]*arr[i])%mod;
		ans = (ans+1LL*acc*(i-1))%mod;
	}
	printf("%d\n",ans);
	return 0;
}