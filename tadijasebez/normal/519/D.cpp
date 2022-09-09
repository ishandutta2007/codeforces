#include <stdio.h>
#include <cstring>
#include <map>
using namespace std;
#define ll long long
const int N=100050;
char word[N];
int x[26];
ll dp[N],sol;
map<ll,int> Map[1000];
int main()
{
	int n,i;
	for(i=0;i<26;i++) scanf("%i",&x[i]);
	scanf("%s",&word);
	n=(unsigned) strlen(word);
	for(i=0;i<n;i++) dp[i+1]=dp[i]+x[word[i]-'a'];
	for(i=0;i<n;i++) sol+=Map[word[i]][dp[i]],Map[word[i]][dp[i+1]]++;
	printf("%lld\n",sol);
	return 0;
}