#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <string>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
int T,n,a,b,c;
char s[109],k[109];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d",&n,&a,&b,&c);
		scanf("%s",s);
		int ans=0;
		for(int i=0;i<n;i++){
			k[i]='0';
			if(s[i]=='R'){
				if(b){
					b--,ans++;
					k[i]='P';
				}
			}
			if(s[i]=='P'){
				if(c){
					c--,ans++;
					k[i]='S';
				}
			}
			if(s[i]=='S'){
				if(a){
					a--,ans++;
					k[i]='R';
				}
			}
		}
		if(ans>=(n+1)/2){
			printf("YES\n");
			for(int i=0;i<n;i++){
				if(k[i]=='0'){
					if(a) a--,k[i]='R';
					else if(b) b--,k[i]='P';
					else if(c) c--,k[i]='S';
				}
				printf("%c",k[i]);
			}
			printf("\n");
		}
		else printf("NO\n");
	}
	return 0;
}