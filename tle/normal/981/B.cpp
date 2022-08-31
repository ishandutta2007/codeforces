#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
long long int ans;
map<int,int> e;
int m,n,a,b;
int main(){
	cin>>m;
	while(m--){
		cin>>a>>b;
		e[a]=b;
		ans+=b;
	}
	cin>>n;
	while(n--){
		cin>>a>>b;
		if(e[a]<b){
			ans-=e[a];
			ans+=b;
		}
	}
	cout<<ans;
}
//only testing, sry