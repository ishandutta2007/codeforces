/*
Contest: -
Problem: Codeforces 1400F
Author: tzc_wk
Time: 2020.8.30
*/
#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define pb			push_back
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define all(a)		a.begin(),a.end()
#define fill0(a)	memset(a,0,sizeof(a))
#define fill1(a)	memset(a,-1,sizeof(a))
#define fillbig(a)	memset(a,0x3f,sizeof(a))
#define y1			y1010101010101
#define y0			y0101010101010
typedef pair<int,int> pii;
typedef long long ll;
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-') neg=-1;
		c=getchar();
	}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	return x*neg;
}
int n,k;
char s[1005];
int ch[50005][10],ed[50005],fail[50005];
int ncnt=0;
inline void insert(string t){
	int cur=0;for(int i=0;i<t.size();i++){
		if(!ch[cur][t[i]-'0']) ch[cur][t[i]-'0']=++ncnt;
		cur=ch[cur][t[i]-'0'];
	}
	ed[cur]++;
}
inline bool check(string t){
	for(int i=0;i<t.size();i++){
		for(int j=i;j<t.size();j++){
			int sum=0;
			for(int k=i;k<=j;k++) sum+=t[k]-'0';
			if(sum!=k&&k%sum==0) return 0;
		}
	}
	return 1;
}
inline void gen(string t,int sum){
	if(sum>k) return;
	if(sum==k){
		if(check(t)) insert(t);
		return;
	}
	for(int i=1;i<=9;i++) gen(t+char(i+'0'),sum+i);
}
inline void rebuild(){
	queue<int> q;
	for(int i=1;i<=9;i++) if(ch[0][i]) q.push(ch[0][i]);
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=1;i<=9;i++){
			if(ch[x][i]) fail[ch[x][i]]=ch[fail[x]][i],q.push(ch[x][i]);
			else ch[x][i]=ch[fail[x]][i];
		}
	}
}
int dp[1005][50005];
int main(){
	cin>>s+1;n=strlen(s+1);k=read();gen("",0);rebuild();
	fillbig(dp);dp[0][0]=0;
	for(int i=0;i<=n-1;i++) for(int j=0;j<=ncnt;j++){
		dp[i+1][j]=min(dp[i+1][j],dp[i][j]+1);
		if(!ed[ch[j][s[i+1]-'0']])
			dp[i+1][ch[j][s[i+1]-'0']]=min(dp[i+1][ch[j][s[i+1]-'0']],dp[i][j]);
	}
	int ans=0x3f3f3f3f;for(int j=0;j<=ncnt;j++) ans=min(ans,dp[n][j]);
	printf("%d\n",ans);
	return 0;
}