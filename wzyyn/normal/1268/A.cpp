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
int n,k;
char a[500005];
char b[500005];
int main(){
	scanf("%d%d",&n,&k);
	scanf("%s",a);
	For(i,0,k-1) b[i]=a[i];
	For(i,0,n-1) if (a[i]!=b[i%k]){
		if (a[i]>b[i%k]){
			++b[k-1];
			Rep(j,k-1,1)
				if (b[j]==58)
					b[j]='0',b[j-1]++;
		}
		break;
	}
	printf("%d\n",n);
	For(i,0,n-1)
		putchar(b[i%k]);
}