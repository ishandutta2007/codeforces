#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll a, b, c, n, i, x, cnt, cost;
vector<ll> A, B, C; string s;

int main(){
	scanf("%lld%lld%lld%lld",&a,&b,&c,&n);
	for(i=1;i<=n;i++){
		cin >> x >> s;
		if(s=="USB") A.push_back(x);
		else B.push_back(x);
	}
	sort(A.begin(),A.end());
	sort(B.begin(),B.end());
	for(i=0;i<min((ll)A.size(),a);i++)
		cnt++, cost+=A[i];
	for(;i<A.size();i++) C.push_back(A[i]);
	for(i=0;i<min((ll)B.size(),b);i++)
		cnt++, cost+=B[i];
	for(;i<B.size();i++) C.push_back(B[i]);
	sort(C.begin(),C.end());
	for(i=0;i<min((ll)C.size(),c);i++)
		cnt++, cost += C[i];
	printf("%lld %lld\n",cnt,cost);
	return 0;
}