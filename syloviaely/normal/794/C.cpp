#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
char ch[310000];
int n,A[30],B[30],ans[310000],x[310000];
int main(){
	scanf("%s",ch+1);
	n=strlen(ch+1); sort(ch+1,ch+n+1);
	int remA=(n+1)/2,remB=n-remA;
	for (int i=1;i<=remA;i++) A[ch[i]-'a']++;
	scanf("%s",ch+1); sort(ch+1,ch+n+1,greater<char>());
	for (int i=1;i<=remB;i++) B[ch[i]-'a']++;
	int R=n;
	for (int now=1;now<=n;now++){
		int LA=26,RA=0,LB=26,RB=0;
		for (int i=0;i<26;i++){
			if (A[i]){
				LA=min(LA,i); RA=max(RA,i);
			}
			if (B[i]){
				LB=min(LB,i); RB=max(RB,i);
			}
		}
		if (now&1){
			if (RB>LA){
				ans[now]=LA; remA--; A[LA]--;
			} else {
				ans[R]=RA; remA--; A[RA]--; R--;
			}
		} else {
			if (LA<RB){
				ans[now]=RB;  remB--; B[RB]--;
			} else {
				ans[R]=LB; remB--; B[LB]--; R--;
			}
		}
	}
	for (int i=1;i<=n;i++) putchar('a'+ans[i]);
	return 0;
}