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
int n,k,r,c=0;
char a[200001];
inline void init(){
	scanf("%d%d%s",&n,&k,&a);
	for(int i=0;i<n;i++)
		c+=max(a[i]-'a','z'-a[i]);
	if(c<k){
		cout<<"-1";return;
	}
	for(int i=0;i<n;i++){
		if(k==0){
			putchar(a[i]);continue;
		}
		r=max(a[i]-'a','z'-a[i]);
	//	cout<<k<<" "<<r<<endl;
		if(k>=r){
			k-=r;
			if(r==a[i]-'a'){
				putchar('a');
			}
			else putchar('z');
			continue;
		}
		if(k<=a[i]-'a'){
			putchar(a[i]-k);k=0;
		}
		else if(k<='z'-a[i]){
			putchar(a[i]+k);k=0;
		}
	}
}
int main(){
	init();
	return 0;
}