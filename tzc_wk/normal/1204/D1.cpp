#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define MOD			1000000007
#define FOR(i,l,r)	for(int i=l;i<=r;i++)
#define REP(i,n)	for(int i=1;i<=n;i++)
#define REP0(i,n)	for(int i=0;i<n;i++)
#define PB			push_back
#define MP			make_pair
#define PII			pair<int,int>
#define VI			vector<int>
#define ALL(x)		(x).begin(),(x).end()
char s[2005];
int pre[2005],suf[2005],lis[2005][2005],nlis[2005];
int n;
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++){
		if(s[i]=='0')	pre[i]=pre[i-1]+1;
		else			pre[i]=pre[i-1];
	}
	for(int i=n;i>=1;i--){
		if(s[i]=='1')	suf[i]=suf[i+1]+1;
		else			suf[i]=suf[i+1];
	}
//	for(int i=1;i<=n;i++)	cout<<pre[i]<<" ";
//	cout<<endl;
//	for(int i=1;i<=n;i++)	cout<<suf[i]<<" ";
//	cout<<endl;
	for(int l=1;l<=n;l++){
		int mx=0;
		for(int r=l;r<=n;r++){
			mx=max(mx,pre[r]+suf[r]);
			lis[l][r]=mx-pre[l-1]-suf[r+1];
//			cout<<l<<" "<<r<<" "<<lis[l][r]<<endl;
		}
	}
	for(int i=1;i<=n;i++){
		if(s[i]=='1'){
//			cout<<i<<endl;
			for(int j=i;j<=n;j++)	pre[j]++;
			for(int j=1;j<=i;j++)	suf[j]--;
			int mx=0;
			memset(nlis,0,sizeof(nlis));
			for(int j=i;j<=n;j++){
				mx=max(mx,pre[j]+suf[j]);
				nlis[j]=mx-pre[i-1]-suf[j+1];
			}
			bool flag=1;
			for(int j=i;j<=n;j++){
				if(nlis[j]!=lis[i][j])	flag=0;
			}
			if(flag){
				s[i]='0';
			}
			else{
				for(int j=i;j<=n;j++)	pre[j]--;
				for(int j=1;j<=i;j++)	suf[j]++;
			}
		}
	}
	for(int i=1;i<=n;i++)	cout<<s[i];
	return 0;
}