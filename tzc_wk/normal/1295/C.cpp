/*




D P 




 l l
*/
#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define put(x)		putchar(x)
#define eoln        put('\n')
#define space		put(' ')
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-')	neg=-1;
		c=getchar();
	}
	while(isdigit(c))	x=x*10+c-'0',c=getchar();
	return x*neg;
}
inline void print(int x){
	if(x<0){
		putchar('-');
		print(abs(x));
		return;
	}
	if(x<=9)	putchar(x+'0');
	else{
		print(x/10);
		putchar(x%10+'0');
	}
}
char s[100005],t[100005];
int nxt[100005][26];
inline void solve(){
	cin>>s+1>>t+1;
	int ls=strlen(s+1);
	fz(i,1,ls){
		fz(j,0,25)	nxt[i][j]=0;
	}
	fz(c,0,25){
		vector<int> v;
		fz(i,1,ls){
			if(s[i]-'a'==c){
				v.push_back(i);
			}
		}
		if(!v.size())	continue;
		for(int i=0;i<(int)v.size()-1;i++){
			for(int j=v[i];j<v[i+1];j++){
				nxt[j][c]=v[i+1];
			}
		}
		fz(i,v[(int)v.size()-1],ls){
			nxt[i][c]=v[0];
		}
		for(int i=1;i<v[0];i++)	nxt[i][c]=v[0];
	}
	int ans=1;
	int cur=0;
	while(s[cur]!=t[1]&&cur<=ls)	cur++;
	if(cur==ls+1){
		puts("-1");
		return;
	}
	int lt=strlen(t+1);
	fz(i,2,lt){
		if(!nxt[cur][t[i]-'a']){
			puts("-1");
			return;
		}
		if(nxt[cur][t[i]-'a']<=cur)	ans++;
		cur=nxt[cur][t[i]-'a'];
	}
	cout<<ans<<endl;
}
int main(){
	int T=read();while(T--)	solve();
	return 0;
}