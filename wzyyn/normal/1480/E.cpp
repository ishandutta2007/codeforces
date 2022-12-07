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
int L,R;
int e[25][25];
int main(){
	scanf("%d%d",&L,&R);
	int p=21;
	e[21][22]=1;
	Rep(i,20,2){
		For(j,i+2,22) e[i][j]=e[i+1][j];
		e[i][i+1]=1<<(20-i);
	}
	e[1][22]=L;
	Rep(i,19,0) if (L+(1<<i)<=R){
		e[1][21-i]=L;
		L+=(1<<i);
	}
	int se=0;
	For(i,1,22) For(j,i+1,22)
		if (e[i][j]) se++;
	printf("YES\n%d %d\n",22,se);
	For(i,1,22) For(j,i+1,22)
		if (e[i][j]) printf("%d %d %d\n",i,j,e[i][j]); 
}