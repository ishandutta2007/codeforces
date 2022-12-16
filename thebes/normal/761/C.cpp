#include <bits/stdc++.h>
using namespace std;

int dp[8], wtf[8], n, m, i;
string s;

int main(){
	for(i=1;i<8;i++) dp[i]=1<<30;
	for(scanf("%d%d",&n,&m),i=1;i<=n;i++){
		cin >> s; copy(dp,dp+8,wtf);
		for(int j=0;j<s.size();j++){
			int idx = 2;
			if(s[j]>='a'&&s[j]<='z') idx = 0;
			else if(s[j]>='0'&&s[j]<='9') idx=1;
			int c = min((int)s.size()-j, j);
			for(int k=0;k<8;k++){
				if(!(k&(1<<idx)))
					wtf[k+(1<<idx)]=min(wtf[k+(1<<idx)],dp[k]+c);
			}
		}
		swap(dp, wtf);
	}
	printf("%d\n",dp[7]);
	return 0;
}