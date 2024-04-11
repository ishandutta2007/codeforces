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
int a,b,k;
void solve1(){
	if (k!=0) puts("No");
	else{
		puts("Yes");
		For(i,1,b) putchar('1');
		For(i,1,a) putchar('0');
		puts("");
		For(i,1,b) putchar('1');
		For(i,1,a) putchar('0');
	}
}
void solve2(){
	if (k>a+b-2) puts("No");
	else if (k==0){
		puts("Yes");
		For(i,1,b) putchar('1');
		For(i,1,a) putchar('0');
		puts("");
		For(i,1,b) putchar('1');
		For(i,1,a) putchar('0');
	}
	else{
		int p1=a+b,p2=a+b-k;
		int rem=b-1;
		puts("Yes");
		For(i,1,a+b)
			if (i==p1||i==p2)
				putchar(i==p2?'1':'0');
			else putchar(rem?'1':'0'),rem-=(rem!=0);
		rem=b-1;
		puts("");
		For(i,1,a+b)
			if (i==p1||i==p2)
				putchar(i==p1?'1':'0');
			else putchar(rem?'1':'0'),rem-=(rem!=0);
	}
}
int main(){
	scanf("%d%d%d",&a,&b,&k);
	if (a==0||b==1) solve1();
	else solve2();
}