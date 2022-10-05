#include <bits/stdc++.h>
using namespace std;
char s[1000005];
int n,z[1000005];
inline void Z_algorithm(){
	int l=0,r=0;
	for(int i=1;i<n;i++){
		if(i<=r)	z[i]=min(z[i-l],r-i);
		while(i+z[i]<n&&s[i+z[i]]==s[z[i]])	z[i]++;
		if(i+z[i]>r){
			l=i;
			r=i+z[i];
		}
	}
}
int main(){
	scanf("%s",s);
	n=strlen(s);
	Z_algorithm();
	int maxx=0,pos=0;
    for(int i=1;i<n;i++){
		if(z[i]==n-i&&maxx>=n-i){
			pos=i;
			break;
		}
		maxx=max(maxx,z[i]);
	}
	if(!pos)	puts("Just a legend");
	else
		for(int i=0;i<n-pos;i++)
			putchar(s[i]);
}