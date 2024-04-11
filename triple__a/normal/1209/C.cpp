#include<bits/stdc++.h>
using namespace std;

const int maxn=200007;
int n;
string s;
int col[maxn];

bool ck(int u){
	for (int i=0;i<n;++i){
		if (s[i]>=u+'0'){
			col[i]=2;
		}
		else{
			col[i]=1;
		}
	}
	for (int i=n-1;i>0;--i){
		if (s[i]<u+'0') break;
		if (s[i]==u+'0') col[i]=1;
	}
	int cnt[]={0,-1,-1};
	for (int i=0;i<n;++i){
		if (s[i]<cnt[col[i]]) return 0;
		cnt[col[i]]=s[i];
	}
	return 1;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		cin>>s;
		bool fg=false;
		for (int i=0;i<9;++i){
			if (ck(i)){
				for (int i=0;i<n;++i){
					cout<<col[i];
				}
				fg=true;
				break;
			}
		}
		if (!fg){
			cout<<"-";
		}
		cout<<endl;
	}
	return 0;
}