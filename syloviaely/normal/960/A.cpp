#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
char ch[110000];
int main(){
	scanf("%s",ch+1); int n=strlen(ch+1); int now=1;
	while (ch[now]=='a') now++;
	int numA=now-1; int pre=now;
	while (ch[now]=='b') now++;
	int numB=now-pre; pre=now;
	while (ch[now]=='c') now++;
	int numC=now-pre;
	//cout<<numA<<" "<<numB<<" "<<numC<<endl;
	if (numA&&numB&&numC&&(numA==numC||numB==numC)&&now>n) printf("YES\n"); else printf("NO\n");
	return 0;
}