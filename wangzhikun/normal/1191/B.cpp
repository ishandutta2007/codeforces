//determined
#include <cmath>
#include <cstdio>
#include <cstring>
#include <complex>
#include <cassert>
#include <iostream>
#include <algorithm>
#define set0(x) memset(x,0,sizeof(x))
#define debug(x) cerr<<#x<<'='<<x<<endl
using namespace std;
typedef long long ll;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();int f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();};
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}
	x*=f;
}

char a[5],b[5],c[5];
int val(char *s){
	int sa = (s[0]-'1');
	if(s[1] == 'm')sa+=9;
	if(s[1] == 's')sa+=18;
	return sa;
}
int main(){
	cin>>a>>b>>c;
	int va = val(a),vb = val(b),vc = val(c);
	if(va>vb)swap(va,vb);if(va>vc)swap(va,vc);if(vb>vc)swap(vb,vc);
	if((va == vb && vb == vc) || (va/9 == vc/9 && va%9+1 == vb%9 && vb%9+1 == vc%9)){
		cout<<0<<endl;
		return 0;
	}
	
	if((va == vb || vb == vc) || (va/9 == vb/9 && ((va%9+1 == vb%9) || (va%9+2 == vb%9))) || (vb/9 == vc/9 && ((vb%9+1 == vc%9) || (vb%9+2 == vc%9)))){
		cout<<1<<endl;
		return 0;
	}
	cout<<2<<endl;
	return 0;
}