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
const int N=500005;
int n,m,a,b,cnt[N];
int A[N],B[N];
set<int> S;
int main(){
	scanf("%d%d%d%d",&n,&m,&a,&b);
	if (a>=m||b>=n) return puts("No"),0;
	For(i,1,a) scanf("%d",&A[i]);
	For(i,1,b) scanf("%d",&B[i]);
	for (;a<m-1;A[++a]=1);
	for (;b<n-1;B[++b]=n+1);
	For(i,1,a) cnt[A[i]]++;
	For(i,1,b) cnt[B[i]]++;
	For(i,1,n+m) if (!cnt[i]) S.insert(i);
	reverse(A+1,A+a+1);
	reverse(B+1,B+b+1);
	puts("Yes");
	for (;a||b;){
		int x=*S.begin();
		S.erase(S.begin());
		//printf("CGT %d %d %d %d\n",x,a,b,S.size());
		int opp=(x<=n?B[b--]:A[a--]);
		printf("%d %d\n",x,opp);
		if (!--cnt[opp]) S.insert(opp);
	}
	int x=*S.begin();
	S.erase(S.begin());
	int y=*S.begin();
	printf("%d %d\n",x,y);
}
/*
4 5 4 2
1 3 3 4
7 8
*/