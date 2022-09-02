// author: xay5421
// created: Thu Jul 22 22:38:25 2021
#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
int Q;
int main(){
	scanf("%d",&Q);
	while(Q--){
		string s,t;
		cin>>s>>t;
		bool can=0;
		rep(i,0,SZ(s)-1){
			for(int j=0;i+j<SZ(s)&&j<SZ(t);++j){
				if(s[i+j]!=t[j])break;
				bool ok=1;
				rep(k,j+1,SZ(t)-1){
					if(i+j-(k-j)<0||s[i+j-(k-j)]!=t[k]){ok=0;break;}
				}
				if(ok){can=1;break;}
			}
			if(can)break;
		}
		if(can)puts("YES");else puts("NO");
	}
	return 0;
}