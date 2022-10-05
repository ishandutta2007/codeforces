#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define put(x)		putchar(x)
#define eoln        put('\n')
#define space		put(' ')
#define int long long
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
struct node{
    int id,x;
    friend bool operator <(node p,node q){return p.x>q.x;}
};
int n,k;
int a[200005],b[200005];
int num[200005];
bool check(int add){
	priority_queue<node>q;
	for(int i=1;i<=n;i++){
		q.push({i,a[i]/b[i]+1});
		num[i]=0;
	}
	for(int i=1;i<=k;i++){
		node now=q.top();
		q.pop();
		if(now.x<i) return 0;
		num[now.id]++;
		int sum=a[now.id]+num[now.id]*add;
		q.push({now.id,sum/b[now.id]+1});
	}
	return 1;
}
signed main(){
	n=read();k=read();
	for(int i=1;i<=n;i++)	a[i]=read();
	for(int i=1;i<=n;i++)	b[i]=read();
	int l=0,r=1e13,ans=-1,mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid))	ans=mid,r=mid-1;
		else			l=mid+1;
	}
	print(ans);
}