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
int n=read(),k=read();
char s[200005];
int a[200005],b[200005];
int main(){
	scanf("%s",s+1);
	cout<<n<<endl;
	go(i,1,n)	a[i]=s[i]-'0',b[i]=a[i];
	go(i,1,k){
		for(int j=i;j<=n;j+=k)	b[j]=b[i];
	}
	bool is=1;
	for(int i=1;i<=n;i++){
		if(a[i]>b[i]){
			is=0;
			break;
		}
		else if(b[i]>a[i]){
			is=1;
			break;
		}
	}
	if(is){
		go(i,1,n)	print(b[i]);
		return 0;
	}
	b[k]++;
	int cur=k;
	while(b[cur]==10)	b[cur]=0,b[--cur]++;
	go(i,1,k){
		for(int j=i;j<=n;j+=k)	b[j]=b[i];
	}
	go(i,1,n)	print(b[i]);
	return 0;
}