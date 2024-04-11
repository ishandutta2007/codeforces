#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,x,A,ans;
bitset<N> S;
int main(){
	scanf("%d",&n);
	while (n--){
		scanf("%d",&x);
		if (x==A)continue;
		else if (S[x]){
			S.reset();
			S[A]=1;
			A=x;
		}
		else S[A]=1,A=x,ans++;
	}
	printf("%d\n",ans);
}