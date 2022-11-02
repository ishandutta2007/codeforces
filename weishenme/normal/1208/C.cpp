#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
const int N=1005;
vector<int > v[N];
int a[N][N],b[N],c[N],n,m,Q,x,y,opt,flag[20];
char s[N];
int main(){
	scanf("%d",&n);
	for (int i=0;i<n/4;i++)
		for (int j=0;j<n/4;j++){
			a[i*4][j*4]=0+(i*(n/4)+j)*16;
			a[i*4][j*4+1]=1+(i*(n/4)+j)*16;
			a[i*4][j*4+2]=2+(i*(n/4)+j)*16;
			a[i*4][j*4+3]=3+(i*(n/4)+j)*16;
			a[i*4+1][j*4]=4+(i*(n/4)+j)*16;
			a[i*4+1][j*4+1]=5+(i*(n/4)+j)*16;
			a[i*4+1][j*4+2]=6+(i*(n/4)+j)*16;
			a[i*4+1][j*4+3]=7+(i*(n/4)+j)*16;
			a[i*4+2][j*4]=8+(i*(n/4)+j)*16;
			a[i*4+2][j*4+1]=9+(i*(n/4)+j)*16;
			a[i*4+2][j*4+2]=10+(i*(n/4)+j)*16;
			a[i*4+2][j*4+3]=11+(i*(n/4)+j)*16;
			a[i*4+3][j*4]=12+(i*(n/4)+j)*16;
			a[i*4+3][j*4+1]=13+(i*(n/4)+j)*16;
			a[i*4+3][j*4+2]=14+(i*(n/4)+j)*16;
			a[i*4+3][j*4+3]=15+(i*(n/4)+j)*16;							
		}
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++)printf("%d ",a[i][j]);
		puts("");
	}	
}