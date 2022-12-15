#include <iostream>
#include <string>
using namespace std;

int N, r[26], ans, i, j, cnt;
string s;

int main(){
	scanf("%d",&N); cin>>s;
	for(i=0;i<N;i++){
		if(s[i] >= 'A' && s[i] <= 'Z'){
			for(j=0,cnt=0;j<26;j++){
				cnt += r[j]; r[j] = 0;
			}
			ans = max(ans,cnt);
		}
		else r[s[i]-'a'] = 1;
	}
	for(j=0,cnt=0;j<26;j++){
		cnt += r[j]; r[j] = 0;
	}
	ans = max(ans,cnt);
	printf("%d\n",ans);
	return 0;
}