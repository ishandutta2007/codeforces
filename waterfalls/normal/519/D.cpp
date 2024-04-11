#include <cstdio>
#include <algorithm>
#include <map>
#include <cstring>

using namespace std;

int val[26];
char s[100013];
long long sums[100001];
map<long long,int> where[26];

int main() {
    for (int i=0;i<26;i++) scanf("%d",&val[i]);
    scanf(" %s",&s);
    int len = strlen(s);
    for (int i=0;i<len;i++) sums[i+1] = sums[i]+val[s[i]-'a'];
    long long ans = 0;
    for (int i=0;i<len;i++) {
        ans+=where[s[i]-'a'][sums[i]];
        where[s[i]-'a'][sums[i]+val[s[i]-'a']]+=1;
    }
    printf("%I64d\n",ans);

    return 0;
}