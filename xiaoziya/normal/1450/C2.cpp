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
		int o[3][2]={0,0,0,0,0,0};
		for(int i=1;i<=n;i++){
			cin>>s[i];
			for(int j=0;j<n;j++)
				if(s[i][j]!='.')
					o[(i+j)%3][s[i][j]=='O']++;
		}
		int mn=min(o[0][0]+o[1][1],min(o[1][0]+o[2][1],o[2][0]+o[0][1]));
		int rec=(o[0][0]+o[1][1]==mn)? 0:(o[1][0]+o[2][1]==mn? 1:2);
		for(int i=1;i<=n;i++){
			for(int j=0;j<n;j++){
				if(s[i][j]=='X'&&(i+j)%3==rec)
					s[i][j]='O';
				if(s[i][j]=='O'&&(i+j)%3==(rec+1)%3)
					s[i][j]='X';
			}
			cout<<s[i]<<"\n";
		}
	}
	return 0;
}