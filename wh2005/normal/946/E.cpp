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
int T,n;
char s[200009];
int cnt[19];
vector<int >v;
bool judge(){
	for(int i=n-1;i>=0;i--){
		cnt[s[i]-'0']--;
		for(int j=s[i]-'0'-1;j>=(i==0);j--){
			v.clear();++cnt[j];
			for(int k=0;k<=9;k++) if(cnt[k]&1) v.push_back(k);
			if(v.size()<=n-i-1){
				for(int k=0;k<i;k++) printf("%c",s[k]);
				printf("%d",j);
				sort(v.begin(),v.end());
				for(int k=n-i-1-v.size();k>=1;k--) printf("9");
				for(int k=v.size()-1;k>=0;k--) printf("%d",v[k]);
				printf("\n");
				return 1; 
			}
			--cnt[j];
		}
	}
	return 0;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%s",s);
		n=strlen(s);memset(cnt,0,sizeof(cnt));
		for(int i=0;i<n;i++) cnt[s[i]-'0']++;
		if(!judge()){
			for(int i=0;i<n-2;i++) printf("9");
			printf("\n");
		}
	}
	return 0;
}