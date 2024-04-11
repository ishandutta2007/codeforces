#include <bits/stdc++.h>
using namespace std;

const int MN = 2e5+5;
int pw[MN]={1}, ha[MN], hb[MN], i, j;
int A(int x,int y){return ha[y]-ha[x-1]*pw[y-x+1];}
int B(int x,int y){return hb[y]-hb[x-1]*pw[y-x+1];}
string a, b;

bool wow(int x,int y,int i,int j){
	if(A(x,y)==B(i,j)) return 1;
	else if((y-x+1)%2==0){
		int l=x+y>>1, k=i+j>>1;
		if(wow(x,l,i,k)&&wow(l+1,y,k+1,j)) return 1;
		if(wow(x,l,k+1,j)&&wow(l+1,y,i,k)) return 1;
	}
	return 0;
}

int main(){
	cin >> a >> b;
	for(i=1;i<=a.size();i++){
		pw[i] = pw[i-1]*131;
		ha[i] = ha[i-1]*131+a[i-1]-'a';
		hb[i] = hb[i-1]*131+b[i-1]-'a';
	}
	printf("%s\n",(wow(1,a.size(),1,b.size()))?"YES":"NO");
	return 0;
}