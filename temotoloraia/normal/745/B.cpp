#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,a,b,c,d;
char ch[505][505];
int main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++){
	cin>>ch[i][j];
	if (ch[i][j]=='.')continue;
	if (a==0)a=i;
	if (i>b)b=i;
	if (j<c || c==0)c=j;
	if (j>d)d=j;
	}
	for (int i=a;i<=b;i++)
	for (int j=c;j<=d;j++)
	if (ch[i][j]=='.'){
		cout<<"NO"<<endl;
		return 0;
	}
	cout<<"YES"<<endl;
	return 0;
}