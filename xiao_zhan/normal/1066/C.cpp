#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,l=1,r=0,pos[200500];

int main() {
	cin.tie(0);
	cin>>t;
	while(t--){
		string s;
		cin>>s>>k;
		if(s=="L"){
			pos[k]=--l;
		}
		if(s=="R"){
			pos[k]=++r;
		}
		if(s=="?"){
			cout<<min(pos[k]-l,r-pos[k])<<'\n';
		}
	}
}