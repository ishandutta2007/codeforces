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

int n,top;
int a[1005],stk[1005];

int main(){
	int T=readint();
	while(T--){
		n=readint();
		for(int i=1;i<=n;i++) a[i]=readint();
		top=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1) stk[++top]=1;
			else{
				while(top&&stk[top]!=a[i]-1) top--;
				stk[top]=a[i];
			}
			for(int i=1;i<=top;i++){
				printf("%d",stk[i]);
				if(i<top) printf(".");
			}
			printf("\n");
		}
	}
	return 0;
}