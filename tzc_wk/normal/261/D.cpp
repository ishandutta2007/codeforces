/*
Contest: -
Problem: Codeforces 261D
Author: tzc_wk
Time: 2020.8.11
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
int k=read(),n=read(),mx=read(),t=read();
int a[100005],dp[100005],bit[100005];
inline void add(int x,int v){for(int i=x;i<=mx;i+=(i&(-i))) bit[i]=max(bit[i],v);}
inline int query(int x){int sum=0;for(int i=x;i;i-=(i&(-i))) sum=max(sum,bit[i]);return sum;}
int main(){
	while(k--){
		fz(i,1,n) a[i]=read();
		map<int,int> mp;int sum=0;
		fz(i,1,n){
			if(!mp[a[i]]) mp[a[i]]++,sum++;
		}
		if(t>=sum){printf("%d\n",sum);continue;}
		fill0(dp);fill0(bit);int ans=0;
		fz(i,1,t) fz(j,1,n){
			int c=query(a[j]-1)+1;
			if(c>dp[j]){
				dp[j]=c;
				ans=max(ans,c);
				add(a[j],c);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}