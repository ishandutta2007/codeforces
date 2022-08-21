#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<math.h>
#include<queue>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
int n,m,ans=0;
char a[100001],b[51];
inline bool match(int cur){
	for(int i=0;i<m;i++)
		if(a[i+cur]!=b[i])
			return false;
	return true;
}
inline void init(){
	scanf("%s%s",&a,&b);
	n=strlen(a);
	m=strlen(b);
	for(int i=0;i<n-m+1;i++){
		//cout<<i<<" "<<i+m-1<<endl;
		if(match(i)){
			a[i+m-1]='?';
			ans++;
		}
	}
	cout<<ans;
}
int main(){
	init();
	return 0;
}