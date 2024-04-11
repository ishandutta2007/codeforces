#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int in(){
	int x;
	scanf("%d",&x);
	return x;
}
const int N=5e5+5;
int n;
int sg[N];
int vis[N];
char s[N];
void solve(){
	scanf("%d",&n);
	scanf("%s",s+1);
	int c0=0,c1=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='R')c0++;
		else c1++;
	}
	if(c0<c1){
		puts("Bob");
		return;	
	}
	if(c0>c1){
		puts("Alice");
		return; 
	}
	int sum=0;
	for(int i=1,j;i<=n;i=j+1){
		for(j=i;j<n&&s[j+1]!=s[j];j++);
		int x=j-i+1;
		while(x>3000)x-=34;
		sum^=sg[x];
	}
	if(sum)puts("Alice");
	else puts("Bob"); 
}
int main(){
	int n=3000;
	int mx=0;
	for(int i=2;i<=n;i++){
		for(int j=0;j<=i;j++)vis[j]=0;
		for(int j=0;j<=i-2;j++){
			vis[sg[j]^sg[i-j-2]]=1;
		}
		for(int j=0;j<=i;j++)if(!vis[j]){sg[i]=j;break;}
	}
	int t=in();
	while(t--)solve(); 
	return 0;
}