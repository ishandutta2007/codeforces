#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
using namespace std;
int tot=(1<<26)-1;
int num;
char ch[110000],s[10];
int check(int k){
	int num=0;
	for (int i=0;i<26;i++) if (k&(1<<i)) num++;
	return num;
}
int main(){
	int n; scanf("%d",&n);
	int ans=0;
	for (;n;n--){
		scanf("%s%s",s+1,ch+1);
		int k1=0; int len=strlen(ch+1);
		for (int i=1;i<=len;i++){
			int k2=ch[i]-'a'; k1|=(1<<k2);
		}
		if (s[1]=='.'){
			tot&=(~k1);
		} else if (s[1]=='!'){
			if (check(tot)==1) ans++;
			tot&=k1;
		} else if (s[1]=='?'){
			if (k1!=tot&&check(tot)==1) ans++;
			tot&=(~k1);
		}
	}
	printf("%d\n",ans);
}