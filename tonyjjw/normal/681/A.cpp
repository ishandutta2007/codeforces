#include<bits/stdc++.h>
using namespace std;

const int MN = 100000 + 1;

int N;
char buf[2000];

int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int a,b;
		scanf("%s%d%d",buf,&a,&b);
		if(a>=2400 && b>a){
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}