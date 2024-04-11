#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
using namespace std;

int F[20000005];
void init(){
	for (int i=2;i<=20000000;i++)
		if (!F[i])
			for (int j=i;j<=20000000;j+=i)
				F[j]+=1
				;
}
void solve(){
	int c,d,x;
	long long ans=0;
	scanf("%d%d%d",&c,&d,&x);
	for (int i=1;i*i<=x;i++)
		if (x%i==0){
			if ((d+x/i)%c==0)
				ans+=1<<F[(d+x/i)/c];
			if (x!=i*i)
				if ((d+i)%c==0)
					ans+=1<<F[(d+i)/c];
		}
	cout<<ans<<endl;
}
int main(){
	init();
	int T;
	scanf("%d",&T);
	while (T--) solve();
}
/*
4
1 1 3
4 2 6
3 3 7
2 7 25
*/