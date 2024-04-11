#include<bits/stdc++.h>
using namespace std;
int n;
int a[1<<24]={};
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		char ch[7];
		scanf("%s",ch);
		a[(1<<(ch[0]-'a'))|(1<<(ch[1]-'a'))|(1<<(ch[2]-'a'))]++;
	}
	for(int i=0;i<24;i++){
		for(int j=0;j<(1<<24);j++){
			if(j&(1<<i)) a[j]+=a[j^(1<<i)];
		}
	}
	int ans=0;
	for(int j=0;j<(1<<24);j++) ans^=(n-a[j])*(n-a[j]);
	printf("%d",ans);
	return 0;
}