#include <iostream>
using namespace std;
string a,b,c,x,y;
int main(int argc, char** argv) {
	int n,k;
	cin >> n >> k >> a;
	b=a.substr(0,k);
	c=b;
	++c[k-1];
	for(int i=k-1;i>0;i--)
		c[i-1]+=(c[i]-48)/10,c[i]-=48,c[i]%=10,c[i]+=48;
	x=b,y=c;
	for(int i=k;i<a.size();i++) x+=x[i-k];
	for(int i=k;i<a.size();i++) y+=y[i-k];
	cout << n << endl;
	if(x>=a) cout << x;
	else cout << y;
	return 0;
}