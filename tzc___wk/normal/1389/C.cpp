/*
Contest: Educational Codeforces Round 92
Problem: Codeforces 1389C
Author: tzc_wk
Time: 2020.7.29
*/
#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define all(a)		a.begin(),a.end()
#define fill0(a)	memset(a,0,sizeof(a))
#define fill1(a)	memset(a,-1,sizeof(a))
#define fillbig(a)	memset(a,0x3f,sizeof(a))
#define fillsmall(a) memset(a,0xcf,sizeof(a))
#define y1			y1010101010101
#define y0			y0101010101010
typedef pair<int,int> pii;
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-') neg=-1;
		c=getchar();
	}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	return x*neg;
}
char s[200005];
signed main(){
	int T=read();
	while(T--){
		cin>>s+1;
		int n=strlen(s+1),ans=0x3f3f3f3f;
		int a[2];
		for(a[1]='0';a[1]<='9';a[1]++){
			for(a[0]='0';a[0]<='9';a[0]++){
				int cur=1,cnt=0;
				for(int i=1;i<=n;i++){
					if(s[i]!=a[cur]) cnt++;
					else cur^=1;
				}
				if(cur==1||(cur==0&&a[1]==a[0])) ans=min(ans,cnt);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}