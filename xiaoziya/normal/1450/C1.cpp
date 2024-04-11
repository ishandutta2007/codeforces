#include<bits/stdc++.h>
using namespace std;
const int maxn=305;
int n,m,T,ans,flg;
string s[maxn];
int main(){
	scanf("%d",&T);
	while(T--){
		ans=flg=0;
		scanf("%d",&n);
		int o[3]={0,0,0};
		for(int i=1;i<=n;i++){
			cin>>s[i];
			for(int j=0;j<n;j++)
				if(s[i][j]=='X')
					o[(i+j)%3]++;
		}
		int mn=min(o[0],min(o[1],o[2])),rec=(o[0]==mn)? 0:(o[1]==mn? 1:2);
		for(int i=1;i<=n;i++){
			for(int j=0;j<n;j++)
				if(s[i][j]=='X'&&(i+j)%3==rec)
					s[i][j]='O';
			cout<<s[i]<<"\n";
		}
	}
	return 0;
}