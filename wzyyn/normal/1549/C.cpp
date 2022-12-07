#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
using namespace std;

const int N=200005;
int n,m,ind[N],ans,Q;
int main(){
	scanf("%d%d",&n,&m);
	int ans=n;
	for (int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		if (x>y) swap(x,y);
		if (!(ind[x]++)) ans--;
	}
	scanf("%d",&Q);
	while (Q--){
		int tp,x,y;
		scanf("%d",&tp);
		if (tp==3)
			printf("%d\n",ans);
		else{
			scanf("%d%d",&x,&y);
			if (x>y) swap(x,y);
			if (tp==1){
				if (!(ind[x]++)) ans--;
			}
			else{
				if (!(--ind[x])) ++ans;
			}
		}
	}
}