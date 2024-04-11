#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 1000000007

int i,j,k,n,m,t,f[200500],sb;

void add(int x,int y){
	for(;x<=200000;x+=(-x&x)){f[x]=max(f[x],y);}
}
int get(int x,int y=0){
	for(;x;x-=(-x&x)){y=max(y,f[x]);}return y;
}
set<int> s[400500];

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&k);
		if(k>i)continue;
		s[i+200000-k].insert(k);
	}
	for(i=1;i<=400000;i++){
		for(auto j:s[i]){
			//cout<<j<<endl;
			sb=get(j-1)+1;
			add(j,sb);
		}
	}
	cout<<get(200000);
}