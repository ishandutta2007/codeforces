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
int n;
int main(){
	scanf("%d",&n);
	printf("0 0\n"); --n;
	for (int i=1;n;i++){
		if (n) printf("0 %d\n",i),n--;
		if (n) printf("%d 0\n",i),n--;
		if (n) printf("0 %d\n",-i),n--;
		if (n) printf("%d 0\n",-i),n--;
	}
}