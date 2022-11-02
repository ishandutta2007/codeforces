#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[8001];
ll p[8001];
ll c[8001];
int main(){
	int t;
	cin >> t;
	while(t--){
		int x,y,z;cin >> x >> y >> z;
		if(y==0){
			if(x!=0){
				for(int i=1; i<=x+1 ;i++) cout << '0';
			}
			if(z!=0){
				for(int i=1; i<=z+1 ;i++) cout << '1';
			}
			cout << '\n';
			continue;
		}
		if(x==0){
			for(int i=1; i<=z+1 ;i++) cout << '1';
			for(int i=1; i<=y ;i++) cout << (i+1)%2;
			cout << '\n';
			continue;
		}
		if(z==0){
			for(int i=1; i<=x+1 ;i++) cout << '0';
			for(int i=1; i<=y ;i++) cout << i%2;
			cout << '\n';
			continue;
		}
		for(int i=1; i<=x+1 ;i++) cout << '0';
		for(int i=1; i<=z+1 ;i++) cout << '1';
		for(int i=1; i<=y-1 ;i++) cout << (i+1)%2;
		cout << '\n';
	}
}