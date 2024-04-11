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
char s[100005],t[100005];
int cur=1,dt=0,f=1;
vector<int> ans;
bool flag=0;
inline void perform(int x){
	if(!x)	return;
	ans.push_back(x);
}
char rev(char c){
	if(c=='1')	return '0';
	return '1';
}
signed main(){
	int T=read();
	while(T--){
		int n=read();
		cin>>s+1>>t+1;
		flag=0;
		cur=1;dt=0;f=1;
		ans.clear();
		fd(i,n,1){
//			printf("%d %d\n",dt,f);
			if(((flag)?(rev(s[(i-dt)/f])):(s[(i-dt)/f]))!=t[i]){
//				printf("%d\n",i);
				if(s[(1-dt)/f]!=t[i]&&flag==1||s[(1-dt)/f]==t[i]&&flag==0){
					perform(1);
				}
				perform(i);
				cur=i;
				dt=i+1-dt;f=-f;
				flag^=1;
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
1001101100
0100110100
1000110100

*/