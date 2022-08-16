#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
int a[1000005];
char s[1000005];

int main(){
	n=readint();
	scanf("%s",s+1);
	int ans=0,lst=0;
	for(int i=1;i<=n;i++){
		a[i]=a[i-1]+(s[i]=='('?1:-1);
		if(a[i]<0&&a[i-1]>=0) lst=i;
		if(a[i]==0&&a[i-1]<0) ans+=i-lst+1;
	}
	if(a[n]!=0) printf("-1\n");
	else printf("%d\n",ans);
	return 0;
}