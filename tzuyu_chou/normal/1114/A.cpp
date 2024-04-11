#include<iostream>
using namespace std;
void del(int& p,int& q){
	int r=min(p,q);
	p-=r;q-=r;
}
int main(){
	ios::sync_with_stdio(false);
	int a,b,c,x,y,z;
	cin >> a >> b >> c >> x >> y >> z;
	del(c,z);del(c,y);del(c,x);del(b,y);del(b,x);del(a,x);
	if(a>0 || b>0 || c>0) cout << "NO\n";
	else cout << "YES\n";
}