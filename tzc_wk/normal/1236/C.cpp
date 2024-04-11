#include <bits/stdc++.h>
using namespace std;
#define ll			long long
#define ld			long double
#define go(i,l,r)	for(int i=l;i<=r;i++)
#define rep(i,n)	for(int i=1;i<=n;i++)
#define rep0(i,n)	for(int i=0;i<n;i++)
#define PB			push_back
#define MP			make_pair
#define PII			pair<int,int>
#define VI			vector<int>
#define ALL(x)		(x).begin(),(x).end()
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
int n,a[315][315],id=0;
int main(){
	n=read();
//	if(n==2)	return puts("3 4\n2 1"),0;
	for(int i=1;i<=n;i++){
		if(i&1){
			for(int j=n;j>=1;j--)	a[j][i]=++id;
		}
		else{
			for(int j=1;j<=n;j++)	a[j][i]=++id;
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			if(i==j)	continue;
//			int cnt=0;
//			for(int k=1;k<=n;k++){
//				for(int l=1;l<=n;l++){
//					if(a[i][k]>a[j][l])	cnt++;
//				}
//			}
//			cout<<cnt<<endl;
//		}
//	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)	cout<<a[i][j]<<" ";
		puts("");
	}
	return 0;
}