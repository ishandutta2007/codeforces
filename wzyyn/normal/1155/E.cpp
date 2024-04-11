#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;
const int mo=1000003;
int ask(int x){
	printf("? %d\n",x);
	fflush(stdout);
	int val;
	scanf("%d",&val);
	if (!val){
		printf("! %d\n",x);
		exit(0);
	}
	return val;
}
int a[mo+3];
int main(){
	For(i,0,15) a[i]=ask(i);
	For(i,0,15) Rep(j,15,i+1) a[j]=(a[j]+mo-a[j-1])%mo;
	Rep(i,15,0) For(j,i+1,mo-1) a[j]=(a[j]+a[j-1])%mo;
	For(i,0,mo-1) if (!a[i]) ask(i);
	printf("! %d\n",-1);
}