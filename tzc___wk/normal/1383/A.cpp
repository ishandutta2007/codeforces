/*
Contest: Codeforces Round #659 (Div.1)
Problem: Codeforces 1383A
Author: tzc_wk
Time: 2020.7.24
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
		if(c=='-')	neg=-1;
		c=getchar();
	}
	while(isdigit(c))	x=x*10+c-'0',c=getchar();
	return x*neg;
}
char s[100005],t[100005],ss[676],tt[676];
int m=0;
bool used[26][26];
int f[26];
signed main(){
	int T=read();
	while(T--){
		int n=read();
		cin>>s+1>>t+1;
		bool flg=0;
		fz(i,1,n)	if(s[i]>t[i])	flg=1;
		if(flg){
			puts("-1");
			continue;
		}
		fill0(used);m=0;
		fz(i,1,n)	if(!used[s[i]-'a'][t[i]-'a']){
			used[s[i]-'a'][t[i]-'a']=1;
			ss[++m]=s[i];
			tt[m]=t[i];
		}
		int ans=0;
		fz(i,0,25){
			int mn=26;
			fz(j,1,m)	if(ss[j]-'a'==i&&tt[j]-'a'!=i)	mn=min(mn,tt[j]-'a');
			if(mn==26)	continue;
			fz(j,1,m)	if(ss[j]-'a'==i&&tt[j]-'a'!=i)	ss[j]=mn+'a';
			ans++;
//			printf("%d\n",mn);
//			cout<<ss+1<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}