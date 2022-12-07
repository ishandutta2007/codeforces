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
const int N=1000005;
int n;
char s[N];
int a[N][2],fa[N];
vector<int> v[N];
int get(int x){
	return x==fa[x]?x:fa[x]=get(fa[x]);
}
int main(){
	scanf("%d",&n);
	scanf("%s",s+1);
	For(i,1,n+1) fa[i]=i;
	Rep(i,n,1){
		a[i][0]=(s[i]=='1'?0:a[i+1][0]+1);
		a[i][1]=(s[i]=='0'?0:a[i+1][1]+1);
	}
	For(i,1,n) v[max(a[i][0],a[i][1])].PB(i);
	For(i,1,n){
		int p=1,val=0;
		for (;;){
			p=get(p);
			if (p==n+1) break;
			p+=i; val++;
		}
		printf("%d ",val);
		for (auto j:v[i])
			fa[j]=j+1;
	}
}