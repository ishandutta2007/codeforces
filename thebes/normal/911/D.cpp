#include <bits/stdc++.h>
using namespace std;

const int MN = 1505;
int n, arr[MN], m, i, x, y, inv, bit[MN];

void upd(int p){for(;p<=n;p+=p&(-p))bit[p]++;}
int qu(int p){int r=0;for(;p>0;p-=p&(-p))r+=bit[p]; return r;}

int main(){
	for(scanf("%d",&n),i=1;i<=n;i++)
		scanf("%d",&arr[i]);
	for(i=n;i>=1;i--){
		inv = (inv+qu(arr[i]))%2;
		upd(arr[i]);
	}
	for(scanf("%d",&m),i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		int l = y-x+1;
		if(l%2==1&&(l+1)%4==0) inv = !inv;
		else if(l%2==0&&(l+2)%4==0) inv = !inv;
		printf("%s\n",(inv)?"odd":"even");
	}
	return 0;
}