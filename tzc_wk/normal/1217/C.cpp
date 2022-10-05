#include <bits/stdc++.h>
using namespace std;
char s[200005];
int n,lead[200005],T;
inline void solve(){
	scanf("%s",s+1);
	n=strlen(s+1);
	memset(lead,0,sizeof(lead));
	for(int i=1;i<=n;i++){
		if(s[i]=='0')	lead[i]=lead[i-1]+1;
		else			lead[i]=0;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='1'){
			int cur=0;
			for(int j=i;j<=min(i+20,n);j++){
				cur=cur*2+s[j]-'0';
				if(cur>=j-i+1&&cur<=j-i+1+lead[i-1])	ans++;
			}
		}
	}
	cout<<ans<<endl;
}
int main(){
	cin>>T;
	while(T--)	solve();
	return 0;
}