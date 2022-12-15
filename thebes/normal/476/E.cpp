#include <bits/stdc++.h>
using namespace std;
const int MN=2002;
int nxt[MN],dp[MN][MN],v[MN][MN],N,S,i,j,k;
string s,t;
int main(){
	cin >> s >> t;
	N=s.size(),S=t.size();
	for(i=0;i<N;i++){
		for(k=0,j=i;j<N;j++){
			if(s[j]==t[k]) k++;
			if(k==t.size()) 
			{nxt[i]=j-i+1;break;}
		}
	}
	v[0][0]=1;
	for(i=0;i<N;i++){
		for(j=0;j<=N;j++){
			if(!v[i][j]) continue;
			if(j!=N) dp[i+1][j+1]=max(dp[i][j],dp[i+1][j+1]),v[i+1][j+1]=1;
			dp[i+1][j]=max(dp[i][j],dp[i+1][j]),v[i+1][j]=1;
			if(nxt[i]&&j+nxt[i]-t.size()<=N){
				dp[i+nxt[i]][j+nxt[i]-t.size()]=
				max(dp[i+nxt[i]][j+nxt[i]-t.size()],dp[i][j]+1);
				v[i+nxt[i]][j+nxt[i]-t.size()]=1;
			}
		}
	}
	for(i=0;i<=N;i++)
		printf("%d ",dp[N][i]);
	return 0;
}