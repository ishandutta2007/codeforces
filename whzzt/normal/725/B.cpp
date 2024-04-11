#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
ll a;char s;long long ans;
int main(){
	scanf("%I64d%c",&a,&s);
	switch(s){
		case 'c':ans++;
		case 'b':ans++;
		case 'a':ans++;
		case 'd':ans++;
		case 'e':ans++;
		case 'f':ans++;
	}
	ans+=(a-1)/4*16;
	if(a%2==0)ans+=7;
	cout<<ans<<endl;
	return 0;
}