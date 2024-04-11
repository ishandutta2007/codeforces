#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,ChuTiRenNiMaSiLe[2005000],pre[2005000];

vector<string> v;
string s,sb;

int main(){
	cin.tie(0);
	cin>>n>>m;
	for(i=0;i<=m+1;i++){
		sb+=".";
	}
	v.push_back(sb);
	for(i=1;i<=n;i++){
		cin>>s;
		s="."+s+".";
		v.push_back(s);
	}
	v.push_back(sb);
	
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(v[i-1][j]=='X'&&v[i][j-1]=='X'){
				ChuTiRenNiMaSiLe[j]=1;
			}
		}
	}
	
	for(i=1;i<=m;i++){
		ChuTiRenNiMaSiLe[i]+=ChuTiRenNiMaSiLe[i-1];
	}
	
	cin>>t;
	while(t--){
		cin>>i>>j;
		if(ChuTiRenNiMaSiLe[j]-ChuTiRenNiMaSiLe[i]){
			cout<<"NO\n";
		}
		else{
			cout<<"YES\n";
		}
	}
}