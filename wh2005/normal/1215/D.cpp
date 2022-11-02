#include<bits/stdc++.h>
using namespace std;
int n;
char s[200009];

int main(){
	scanf("%d",&n);
	gets(s);
	gets(s);
	int l=0,r=0,suma=0,sumb=0;
	for(int i=1;i<=n;i++){
		if(s[i-1]=='?'){
			if(i<=(n/2)) l++;
			else r++;
		}
		else{
			if(i<=(n/2)) suma+=s[i-1]-'0';
			else sumb+=s[i-1]-'0';
		}
	}
	if(l==r){
		if(suma==sumb) printf("Bicarp\n");
		else printf("Monocarp\n");
		return 0;
	}
	if(l>r){
		if(suma>=sumb) printf("Monocarp\n");
		else{
			l-=r;
			if(2*(sumb-suma)==9*l) printf("Bicarp\n");
			else printf("Monocarp\n");
		}
		return 0;
	} 
	if(l<r){
		if(suma<sumb) printf("Monocarp\n");
		else{
			r-=l;
			if(2*(suma-sumb)==9*r) printf("Bicarp\n");
			else printf("Monocarp\n");
		}
		return 0;
	} 
	return 0;
}