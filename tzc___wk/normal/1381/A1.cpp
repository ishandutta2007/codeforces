/*
Contest: Codeforces Round #658 (Div.1)
Problem: Codeforces 1381A
Author: tzc_wk
Time: 2020.7.17
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
char s[1005],t[1005];
vector<int> ans;
inline void perform(int x){
	if(!x)	return;
	ans.push_back(x);
	fz(i,1,x){
		if(s[i]=='1')	s[i]='0';
		else			s[i]='1';
	}
	reverse(s+1,s+x+1);
}
signed main(){
	int T=read();
	while(T--){
		int n=read();
		cin>>s+1>>t+1;
		ans.clear();
		fd(i,n,1){
			if(s[i]!=t[i]){
				int pos=0;
				fz(j,1,i)	if(s[j]!=s[i]){
					pos=j;
					break;
				}
				perform(pos);
				perform(i);
			}
		}
		cout<<ans.size()<<" ";
		foreach(it,ans)	cout<<*it<<" ";
		puts("");
	}
	return 0;
}
/*
10
0110011011
1110011011
0010011000
0110011000
1001100100
0001100100
1001110100
1001110100
0110110100
1110110100
1000110100

*/