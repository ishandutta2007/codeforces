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
#define all(v) v.begin(),v.end()
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	printf("%d\n",3*n+4);
	printf("0 0\n");
	For(i,1,n+1){
		printf("%d %d\n",i,i);
		printf("%d %d\n",i-1,i);
		printf("%d %d\n",i,i-1);
	}
}