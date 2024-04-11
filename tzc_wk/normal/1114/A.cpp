#include <bits/stdc++.h>
using namespace std;
int x,y,z,a,b,c;
int main(){
	cin>>x>>y>>z>>a>>b>>c;
	if(x>a)return puts("NO"),0;
	a-=x;
	a+=b;
	if(y>a)return puts("NO"),0;
	a-=y,a+=c;
	if(z>a)return puts("NO"),0;
	puts("YES");
	return 0;
}