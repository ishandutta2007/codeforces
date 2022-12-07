#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
#define pll pair<ll,ll> 
#define y1 orzkcz
using namespace std;
 
const int N=1000005;
char l[N],r[N];
int n;
int main(){
	scanf("%d",&n);
	scanf("%s",l+1);
	scanf("%s",r+1);
	if (l[1]==r[1]){
		if (r[n]=='0'){
			bool flg=0;
			For(j,1,n-1) if (l[j]!=r[j]&&l[j+1]==r[j+1]) flg=1;
			if (flg) r[n]='1';
		}
		printf("%s\n",r+1);
	}
	else{
		For(i,1,n) putchar('1');
	}
}
/*
0 1 3 0
4 1 7 0
8 1 11 0
12 1 15 0
*/