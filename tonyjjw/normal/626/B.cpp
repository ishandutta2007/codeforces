//*
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;
typedef long long ll;

const int MN = 200+1;

char s[MN];

int main(){
	int N;
	scanf("%d",&N);
	scanf("%s",s);
	int r=0,g=0,b=0;
	for(int i=0;i<N;i++){
		if(s[i]=='R'){
			r++;
		}
		if(s[i]=='G'){
			g++;
		}
		if(s[i]=='B'){
			b++;
		}
	}
	if(r>0 && g>0 && b>0){
		puts("BGR");
		return 0;
	}
	if(r==0 && g==0){
		puts("B");
		return 0;
	}
	if(r==0 && b==0){
		puts("G");
		return 0;
	}
	if(b==0 && g==0){
		puts("R");
		return 0;
	}
	if(r==0){
		if(g>1 && b>1){
			puts("BGR");
			return 0;
		}
		if(g==1 && b==1){
			puts("R");
			return 0;
		}
		if(g>1){
			puts("BR");
			return 0;
		}
		puts("GR");
		return 0;
	}
	if(g==0){
		if(r>1 && b>1){
			puts("BGR");
			return 0;
		}
		if(r==1 && b==1){
			puts("G");
			return 0;
		}
		if(r>1){
			puts("BG");
			return 0;
		}
		puts("GR");
		return 0;
	}
	if(b==0){
		if(g>1 && r>1){
			puts("BGR");
			return 0;
		}
		if(g==1 && r==1){
			puts("B");
			return 0;
		}
		if(g>1){
			puts("BR");
			return 0;
		}
		puts("BG");
		return 0;
	}
	return 0;
}

//*/