#include<bits/stdc++.h>

#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
char s[100005];

struct bg{
	int n;
	int a[100005];
}ans,x1,x2;

void print(bg x){
	for(int i=x.n;i>=1;i--) printf("%d",x.a[i]);
	printf("\n");
}

bool comp(bg x,bg y){
	if(x.n>y.n) return true;
	if(x.n<y.n) return false;
	for(int i=n;i>=1;i--){
		if(x.a[i]>y.a[i]) return true;
		if(x.a[i]<y.a[i]) return false;
	}
	return false;
}

bg add(bg x,bg y){
    if(x.n>y.n) swap(x,y);
	bg ret;
	ret.n=max(y.n,x.n);
	memcpy(ret.a,y.a,sizeof(ret.a));
	for(int i=1;i<=ret.n;i++) ret.a[i]+=i<=x.n?x.a[i]:0;
	for(int i=1;i<=ret.n;i++){
		ret.a[i+1]+=ret.a[i]/10;
		ret.a[i]%=10;
	}
	if(ret.a[ret.n+1]) ret.n++;
	return ret;
}

bg st(int x){
	x1.n=x,x2.n=n-x;
	for(int i=1;i<=x1.n;i++) x1.a[i]=s[x-i+1]-'0';
	for(int i=1;i<=x2.n;i++) x2.a[n-i-x+1]=s[i+x]-'0';
	return add(x1,x2);
}

int main(){
	n=readint();
	scanf("%s",s+1);
	int m1=n/2,m2=m1+1,m3=m1-1;
	while(m2<=n&&s[m2+1]=='0') m2++;
	while(m3>=1&&s[m3+1]=='0') m3--;
	ans.n=1<<30;
	if(m1>=1&&m1<=n&&s[m1+1]!='0') ans=st(m1);
	if(m2>=1&&m2<=n){
		bg x=st(m2);
		if(comp(ans,x)) ans=x;
	}
	if(m3>=1&&m3<=n){
		bg x=st(m3);
		if(comp(ans,x)) ans=x;
	}
	print(ans);
	return 0;
}