#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	cin>>T;
	while(T--){
		int sr;
		int n,m;
		cin>>n>>m;
		int H1,H2;
		cout<<"SCAN "<<1<<" "<<1<<endl;
		cin>>sr;
		H1=sr+4;
		cout<<"SCAN "<<n<<" "<<1<<endl;
		cin>>sr;
		H2=2*n-2-sr;
		assert((H1+H2)%2==0);
		int AC=(H1+H2)/2,BD=(H1-H2)/2;
		assert(AC>=1&&AC<=n+n);
		assert(BD>=1&&BD<=m+m);
		int ss;
		ss=AC/2;
		cout<<"SCAN "<<ss<<" "<<1<<endl;
		cin>>sr;
		int CA=sr+2-BD;
		ss=BD/2;
		cout<<"SCAN "<<1<<" "<<ss<<endl;
		cin>>sr;
		int DB=sr+2-AC;
		assert((AC+CA)%2==0);
		assert((BD+DB)%2==0);
		int a=(AC+CA)/2,c=AC-a;
		int b=(BD+DB)/2,d=BD-b;
		cout<<"DIG "<<a<<" "<<b<<endl;
		int fl;
		cin>>fl;
		if(fl){
			cout<<"DIG "<<c<<" "<<d<<endl;
			cin>>fl;
			continue;
		}
		cout<<"DIG "<<a<<" "<<d<<endl;
		cin>>fl;
		cout<<"DIG "<<c<<" "<<b<<endl;
		cin>>fl;
	}
	return 0;
}