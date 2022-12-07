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
const int mo=998244353;
const int N=3005;
char s[N],t[N];
int n,m,f[N][N];
void UPD(int &x,int y){
	(x+=y)>=mo?x-=mo:233;
}
bool mat(char x,char y){
	return x==y||y=='?';
}
int main(){
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1);
	m=strlen(t+1);
	For(i,m+1,n) t[i]='?';
	For(i,1,n) if (mat(s[1],t[i])) f[1][i]=2;
	For(i,1,n-1) For(j,1,n){
		if (mat(s[i+1],t[j-1])) UPD(f[i+1][j-1],f[i][j]);
		if (mat(s[i+1],t[j+i])) UPD(f[i+1][j],f[i][j]); 
	}
	int ans=0;
	For(i,m,n) UPD(ans,f[i][1]);
	printf("%d ",ans);
}