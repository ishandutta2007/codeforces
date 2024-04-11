#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int i,j,k,n,m,t,res;
char s[500500];
string sb;

bool chk(int x){
	if(x<1)return 0;
	return (s[x]=='a'&&s[x+1]=='b'&&s[x+2]=='c');
}

int main(){
	ios::sync_with_stdio(0);
	cin>>n>>t;
	cin>>s+1;
	for(i=1;i<=n;i++){
		if(chk(i)){
			res++;
		}
	}
	while(t--){
		cin>>k>>sb;
		if(chk(k))res--;
		if(chk(k-1))res--;
		if(chk(k-2))res--;
		
		s[k]=sb[0];
		
		if(chk(k))res++;
		if(chk(k-1))res++;
		if(chk(k-2))res++;
		
		cout<<res<<'\n';
	}
}