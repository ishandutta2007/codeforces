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
int q[100005];
int main(){
	for (int i=3;1ll*i*i/2<=(1<<30);i+=2)
		q[++*q]=i*i/2+1;
	int T;
	scanf("%d",&T);
	while (T--){
		int x;
		scanf("%d",&x);
		printf("%d\n",lower_bound(q+1,q+*q+1,x+1)-q-1);
	}
}
/*
b+c+b^2=c^2
b^2+b=c^2-c
c=b+1
*/