#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=1e9+7;
string s;
int match[703],st[703],top=1;
int n,dp[703][703][4][4];
signed main(){
	cin>>s;
	n=s.size();
	s=" "+s;
	for(int i=1;i<=n;i++){
		if(s[i]=='(')	st[++top]=i;
		else			match[st[top--]]=i;
	}
	for(int i=n-1;i>=1;i--){
		for(int j=i+1;j<=n;j++){
			for(int k1=1;k1<=3;k1++){
				for(int k2=1;k2<=3;k2++){
					if(match[i]==j){
						if((k1==1||k2==1)&&!(k1==1&&k2==1)){
							if(j-1==i){
//								cout<<i<<" "<<j<<" "<<k1<<" "<<k2<<endl;
								dp[i][j][k1][k2]=1;
								continue;
							}
							for(int k3=1;k3<=3;k3++){
								for(int k4=1;k4<=3;k4++){
									if(!(k1>1&&k1==k3||k2>1&&k2==k4)){
//										cout<<k1<<" "<<k3<<" "<<k4<<" "<<k2<<endl;
										dp[i][j][k1][k2]=(dp[i][j][k1][k2]+dp[i+1][j-1][k3][k4])%MOD;
									}
								}
							}
						}
					}
					else{
						if(!match[i]||match[i]>j)	continue;
						if(k1>1){
							for(int k3=1;k3<=3;k3++){
								dp[i][j][k1][k2]=(dp[i][j][k1][k2]+dp[i][match[i]][k1][1]*dp[match[i]+1][j][k3][k2]%MOD)%MOD;
							}
						}
						else{
							for(int k3=2;k3<=3;k3++){
								for(int k4=1;k4<=3;k4++){
									if(k3!=k4){
										dp[i][j][k1][k2]=(dp[i][j][k1][k2]+dp[i][match[i]][k1][k3]*dp[match[i]+1][j][k4][k2]%MOD)%MOD;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	int ans=0;
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			ans=(ans+dp[1][n][i][j])%MOD;
		}
	}
	cout<<ans<<endl;
}
/*
()()()()()()()()()()()(())
*/