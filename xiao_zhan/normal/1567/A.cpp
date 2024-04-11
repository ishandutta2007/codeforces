#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
char s[1005],s2[1005];
int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>s+1;
		memset(s2,0,sizeof(s2));
		for(i=1;i<=n;i++){
			if(s[i]=='U'){
				s2[i]='D';
			}
			if(s[i]=='D'){
				s2[i]='U';
			}
		}
		for(i=1;i<=n;i++){
			if(s2[i]){
				cout<<s2[i];
				continue;
			}
			else{
				if(s2[i-1]=='L'){
					s2[i]='R';
				}
				else{
					s2[i]='L';
				}
				cout<<s2[i];
			}
		}
		cout<<endl;
	}
}