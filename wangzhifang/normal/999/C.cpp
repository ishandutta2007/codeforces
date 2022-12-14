#include <cstdio>
#include <cstring>
#define max_n 400000
using namespace std;
int ton[26];
char s[max_n];
int main() {
	int n,k,i;
	scanf("%d%d\n",& n,& k);
	for(i = 0; i < n; i ++) {
		scanf("%c",s+i);
		ton[s[i]-'a']++;
	}
	for(i = 0; i < 26; i ++)
		if(ton[i]<k)
			k-=ton[i];
		else {
			ton[i]=k;
			k=0;
		}
	for(i = 0; i < n; i ++)
		if(ton[s[i]-'a'])
			ton[s[i]-'a']--;
		else
			printf("%c",s[i]);
	return 0;
}