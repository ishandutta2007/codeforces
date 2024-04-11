#include <bits/stdc++.h>
#define ll long long
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
using namespace std;
const int MOD=1e9+7,N=100005;
const ll INF=1e11;
int c[5][5],s,a,b;
char ch;
int main(){
	for (int i=1;i<=4;i++)
	for (int j=1;j<=4;j++){
	cin>>ch;
	if (ch=='x')c[i][j]=1;
	else if (ch=='o')c[i][j]=-1;
	}
	for (int i=1;i<=4;i++)
	for (int j=1;j<=4;j++){
		if (j<=2){
		a=0;
		b=1;
		s=c[i][j]+c[i+a][j+b]+c[i+2*a][j+2*b];
		if (s>=2){cout<<"YES"<<endl;return 0;}
		}
		if (i<=2){
		a=1;
		b=0;
		s=c[i][j]+c[i+a][j+b]+c[i+2*a][j+2*b];
		if (s>=2){cout<<"YES"<<endl;return 0;}
		}
		if (i<=2&&j<=2){
		a=1;
		b=1;
		s=c[i][j]+c[i+a][j+b]+c[i+2*a][j+2*b];
		if (s>=2){cout<<"YES"<<endl;return 0;}
		}
		if (i>=3&&j<=2){
		a=-1;
		b=1;
		s=c[i][j]+c[i+a][j+b]+c[i+2*a][j+2*b];
		if (s>=2){cout<<"YES"<<endl;return 0;}
		}
	}
	cout<<"NO"<<endl;
    return 0;
}