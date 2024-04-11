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

int n,m;

bool Query(int r,int c,int i1,int j1,int i2,int j2){
	printf("? %d %d %d %d %d %d\n",r,c,i1,j1,i2,j2);
	fflush(stdout);
	int x;
	scanf("%d",&x);
	return x;
}
int main(){
	scanf("%d%d",&n,&m);
	int l1=n,l2=m,v1=n,v2=m;
	for (int i=2;i<=l1;i++) if (l1%i==0){
		for (;l1%i==0;l1/=i);
		for (;v1%i==0;v1/=i){
			bool fl=0;
			if (i==2) fl=Query(v1/2,m,1,1,1+v1/2,1);
			else fl=Query((v1-v1/i)/2,m,1,1,1+(v1-v1/i)/2,1)&
					Query((v1-v1/i)/2,m,1,1,1+v1/i+(v1-v1/i)/2,1);
			if (!fl) break;
		}
	}
	for (int i=2;i<=l2;i++) if (l2%i==0){
		for (;l2%i==0;l2/=i);
		for (;v2%i==0;v2/=i){
			bool fl=0;
			if (i==2) fl=Query(n,v2/2,1,1,1,1+v2/2);
			else fl=Query(n,(v2-v2/i)/2,1,1,1,1+(v2-v2/i)/2)&
					Query(n,(v2-v2/i)/2,1,1,1,1+(v2-v2/i)/2+v2/i);
			if (!fl) break;
		}
	}
	int s1=0,s2=0;
	for (int i=1;i<=n;i++) if (i%v1==0&&n%i==0) s1++;
	for (int i=1;i<=m;i++) if (i%v2==0&&m%i==0) s2++;
	printf("! %d\n",s1*s2);
}
/*
0 1 3 0
4 1 7 0
8 1 11 0
12 1 15 0
*/