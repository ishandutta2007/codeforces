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

const int N=250005;
int n,m;
vector<int> v[N];
void check(int x,vector<int> val){
	int p=-1;
	For(i,1,n){
		int c=0;
		For(j,0,m-1) c+=(val[j]!=v[i][j]);
		if (c>2) p=i;
		if (c>4){
			return;
		}
	}
	if (p==-1){
		puts("Yes");
		For(i,0,m-1) printf("%d ",val[i]);
		puts("");
		exit(0);
	}
	else{
		if (x==3) return;
		For(j,0,m-1)
			if (val[j]!=v[p][j]){
				int t=val[j];
				val[j]=v[p][j];
				check(x+1,val);
				val[j]=t;
			}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,n){
		v[i].resize(m);
		For(j,0,m-1) scanf("%d",&v[i][j]);
	}
	check(1,v[1]);
	puts("No");
}