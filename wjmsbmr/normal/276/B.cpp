#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int s[26];char t[1000000];
int main()
{
    scanf("%s",t);
    int n=strlen(t);
    for(int i=0;i<n;i++)s[t[i]-'a']++;
    for(int i=0;i<26;i++)s[i]%=2;
    int S=0;
    for(int i=0;i<26;i++)S+=s[i];
    bool F=1;
    while(S>=2){S--;F^=1;}
    puts(F?"First":"Second");
    return 0;
}