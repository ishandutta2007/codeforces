#include<bits/stdc++.h>

using namespace std;

int main()
{
    char c[1001];
    scanf("%s",&c);
    string s=c;
    bool odd[26];
    memset(odd,0,sizeof(odd));
    int k=0;
    for(int i=0;i<s.length();i++)
        if(odd[s[i]-'a']=!odd[s[i]-'a'])
            k++;
        else
            k--;
    if(k<=1||(k>1&&k%2))
        printf("First");
    else
        printf("Second");
}