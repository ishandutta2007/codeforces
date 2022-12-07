#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
char s[5];
int n,Q,x,s1,s2,a[100005];
void change(int x,int v){
	s1-=a[x]/4; s2-=a[x]/2;
	a[x]+=v;
	s1+=a[x]/4; s2+=a[x]/2;
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&x),change(x,1);
	scanf("%d",&Q);
	For(i,1,Q){
		scanf("%s%d",s+1,&x);
		change(x,(s[1]=='+'?1:-1));
		puts(s1>=1&&s2>=4?"YES":"NO");
	}
}