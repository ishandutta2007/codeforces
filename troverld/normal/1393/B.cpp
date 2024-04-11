#include<bits/stdc++.h>
using namespace std;
int n,cnt[100100],tot[100100];
void funcp(int i){
	if(cnt[i]>=8)tot[8]++;
	else if(cnt[i]>=6)tot[6]++; 
	else if(cnt[i]>=4)tot[4]++; 
	else if(cnt[i]>=2)tot[2]++; 
}
void funcm(int i){
	if(cnt[i]>=8)tot[8]--;
	else if(cnt[i]>=6)tot[6]--; 
	else if(cnt[i]>=4)tot[4]--; 
	else if(cnt[i]>=2)tot[2]--; 
}
int main(){
	scanf("%d",&n);
	for(int x;n--;)scanf("%d",&x),cnt[x]++;
	for(int i=1;i<=100000;i++)funcp(i);
	scanf("%d",&n);
	char s[10];
	for(int x;n--;){
		scanf("%s%d",s,&x);
		funcm(x);
		if(s[0]=='+')cnt[x]++;
		else cnt[x]--;
		funcp(x);
		int a=tot[2]*2,b=tot[4]*4,c=tot[6]*6,d=tot[8]*8;
		if(!b&&!c&&!d){puts("NO");continue;}
		b-=4;
		a+=b+c+d;
		if(a<4){puts("NO");continue;}
		puts("YES");
	}
	return 0;
}