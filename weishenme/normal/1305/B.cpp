#include<bits/stdc++.h>
using namespace std;
const int N=200005;
char s[N];
int main(){
	scanf("%s",s+1);
	int n=strlen(s+1);
	for (int i=0;i<=n;i++){
		int cnt1=0,cnt2=0;
		for (int j=1;j<=i;j++)
			if (s[j]=='(')cnt1++;
		for (int j=i+1;j<=n;j++)
			if (s[j]==')')cnt2++;
		if (cnt1==cnt2){
			if (!cnt1){
				puts("0");
				return 0;
			}
			printf("%d\n",1);
			printf("%d\n",cnt1*2);
			for (int j=1;j<=i;j++)
				if (s[j]=='(')printf("%d ",j);
			for (int j=i+1;j<=n;j++)
				if (s[j]==')')printf("%d ",j);
			return 0;
		}
	}
}