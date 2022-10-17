#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,t,n,m,res,l,r;
char s[100500];
int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	//scanf("%d",&t);
	while(t--){
		cin>>s+1;
		n=strlen(s+1);
		res=2;
		k=0;
		for(i=1;i<=n;i++){
			k+=(s[i]=='0');
		}
		if(!k){cout<<0<<'\n';continue;}
		l=1;r=n;
		while(l<=r){
			if(s[l]=='1'){l++;continue;}
			if(s[r]=='1'){r--;continue;}
			break;
		}
		k=0;
		for(i=l;i<=r;i++){
			k+=s[i]=='1';
		}
		if(k){
			cout<<'2'<<'\n';
		}
		else{
			cout<<'1'<<'\n';
		}
	}
}