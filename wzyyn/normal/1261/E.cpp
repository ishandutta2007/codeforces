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
#define UPD(x,y) (((x)+=(y))>=mo?x-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
using namespace std;
int n,a[1005],id[1005];
int s[1005][1005];
bool cmp(int x,int y){
	return a[x]<a[y];
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]),id[i]=i;
	sort(id+1,id+n+1,cmp);
	s[id[1]][2]=1;
	For(i,2,n){
		int fl=0;
		//printf("%d ",id[i]);
		For(j,1,i-1) s[id[j]][i+1]=(a[id[j]]>=i);
		For(j,1,i-1) if (s[id[j]][i+1]!=s[id[j]][i]) fl=1;
		s[id[i]][i+1]=1;
		For(j,1,min(a[id[i]],i)-1) s[id[i]][i+fl-j]=1;
	}
	printf("%d\n",n+1);
	For(i,1,n+1){
		For(j,1,n) putchar('0'+s[j][i]);
		puts("");
	}
}
/*
101
011
110
111
*/