#include<bits/stdc++.h>
using namespace std;

const int maxn=1007;
char s[maxn],ans[maxn];
int n,u,v,w,test=0;
int main(){
	int t;
	scanf("%d",&t);
	while (t--){
		scanf("%d%d%d%d",&n,&u,&v,&w);
		test=0;
		memset(ans,0,sizeof(ans));
		for (int i=0;i<n;++i){
			cin>>s[i];
		}
		for (int i=0;i<n;++i){
			if (s[i]=='R'){
				if (v){
					v--;
					ans[i]='P';
					test++;
				}
			}
			if (s[i]=='P'){
				if (w){
					w--;
					ans[i]='S';
					test++;
				}
			}
			if (s[i]=='S'){
				if (u){
					u--;
					ans[i]='R';
					test++;
				}
			}
		}
		if (test>=(n+1)/2){
			cout<<"YES"<<endl;
			for (int i=0;i<n;++i){
				if (ans[i]){
					cout<<ans[i];
					continue;
				} 
				if (u){
					u--;
					cout<<"R";
					continue;
				}
				if (v){
					v--;
					cout<<"P";
					continue;
				}
				w--;
				cout<<"S";
			}
			cout<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
}