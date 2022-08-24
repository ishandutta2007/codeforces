#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
char ch[10000],s[100];
int main(){
	s[1]='C'; s[2]='O';
	s[3]='D'; s[4]='E';
	s[5]='F'; s[6]='O';
	s[7]='R'; s[8]='C';
	s[9]='E'; s[10]='S';
	scanf("%s",ch+1);
	int len=strlen(ch+1); if (len<10) {printf("NO"); return 0;}
	int k1=10,k2=10;
	for (int i=1;i<=10;i++) if (ch[i]!=s[i]){k1=i-1; break;}
	for (int i=1;i<=10;i++) if (ch[len-i+1]!=s[11-i]){k2=i-1; break;}
	if (k1+k2>=10) cout<<"YES"<<endl; else cout<<"NO"<<endl;
}