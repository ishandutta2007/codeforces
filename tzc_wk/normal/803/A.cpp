#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[105][105];
void solve(int n,int pos,int k){
	if(k==1){
		a[pos][pos]=1;
		return;
	}
	if(k==0)	return;
    if(k<=n*2-1){
        for(int i=pos;i<=pos+(k-1>>1);i++)	a[pos][i]=a[i][pos]=1;
        solve(n-1,pos+1,k&1^1);
    }
	else{
		for(int i=pos;i<=pos+n-1;i++)	a[pos][i]=a[i][pos]=1;
		solve(n-1,pos+1,k-(n*2-1));
	}
}
int main(){
	cin>>n>>k;
	if(k>n*n)	return puts("-1"),0;
	solve(n,1,k);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}