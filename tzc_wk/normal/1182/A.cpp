#include <bits/stdc++.h>
using namespace std;
long long x;
int main(){
	scanf("%I64d",&x);
	printf("%I64d\n",(x&1ll)?0:1ll<<(x>>1));
}