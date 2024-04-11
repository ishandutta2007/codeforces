#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

string s[26]={"0","1","00","01","10","11","000","001","010","011","100","101","110","111",
"0000","0001","0010","0100","0110","0111","1000","1001","1010","1011","1100","1101"};

const int Maxn=10000000;

bool mp[100000];
int ch[Maxn][2],tot=1;

int str[3005],f[3005][3005],ans;

void insert(int x) {
  for(int i=x;i>0;i--) {
  	int s=0;
  	for(int j=x;j>=max(x-3,i);j--) {
  		s=s*10+(str[j]+'0')%10;
  		if (mp[s]) f[i][x]=(f[i][x]+f[i][j-1])%MOD;
	  }
  }
  int now=1;
  bool ok=0;
  for(int i=x;i>0;i--) {
  	if (!ch[now][str[i]]) {
  		ch[now][str[i]]=++tot;
  		ok=1;
	  }
	now=ch[now][str[i]];
	if (ok) ans=(ans+f[i][x])%MOD;
  }
}

int main() {
  for(int i=0;i<26;i++) {
  	int sum=0;
  	for(int j=s[i].length()-1;j>=0;j--) sum=sum*10+s[i][j]%10;
  	mp[sum]=1;
  }
  int m;
  scanf("%d",&m);
  for(int i=1;i<=m;i++) {
  	scanf("%d",&str[i]);
  	f[i][i-1]=1;
  	insert(i);
  	printf("%d\n",ans);
  }
  return 0;
}