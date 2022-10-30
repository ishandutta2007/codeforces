#include<iostream>
using namespace std;
int qry(int x,int y){
	cout << "? " << x << ' ' << y << endl;
	char c;
	cin >> c;
	return (c=='x');
}
void solve(){
	int tmp=qry(0,1);
	if(tmp){
		cout << "! " << 1 << endl;
		return;
	}
	int cur=1;
	while(true){
		int res=qry(cur,cur*2);
		if(res) break;
		cur*=2;
	}
	int ans=cur;
	for(int i=cur/2; i>=1 ;i/=2){
		int res=qry(ans,ans+i);
		if(!res) ans+=i;
	}
	cout << "! " << ans+1 << endl;
}
int main(){
	ios::sync_with_stdio(false);
	string s;
	while(true){
		cin >> s;
		if(s=="start") solve();
		else break;
	}
}