#include <bits/stdc++.h>
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define ll long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;
const int MOD=1e9+7,N=1005;
const int INF=1e8;
int n,m,r1,c1,r2,c2;
char ch[N][N];
int R[N][N];
int C[N][N];
int np;
int a[N*10],b[N*10];
bool check (int a, int b, int c, int d){
	if (ch[a][b]=='*' || ch[c][d]=='*')return 0;
	if (a==c && R[a][b]-R[c][d]==b-d)return 1;
	if (b==d && C[a][b]-C[c][d]==a-c)return 1;
	return 0;
}
int main()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++){
		cin>>ch[i][j];
		if (ch[i][j]=='S')r1=i,c1=j;
		if (ch[i][j]=='T')r2=i,c2=j;
		R[i][j]=R[i][j-1];
		C[i][j]=C[i-1][j];
		if (ch[i][j]!='*')R[i][j]++,C[i][j]++;
	}
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
	if (check(r1,c1,i,j)){
		np++;
		a[np]=i;
		b[np]=j;
	}
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
	if (check(r2,c2,i,j)){
		for (int l=1;l<=np;l++)
		if (check(a[l],b[l],i,j)){
			cout<<"YES"<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
    return 0;
}