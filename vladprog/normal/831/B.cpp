#include<bits/stdc++.h>

using namespace std;

int main()
{
    char c1[27],c2[27],c[1001];
    scanf("%s%s%s",c1,c2,c);
    map<char,char> m;
    for(int i=0;i<26;i++)
        m.insert(make_pair(c1[i],c2[i])),
        m.insert(make_pair(c1[i]+'A'-'a',c2[i]+'A'-'a'));
    string s=c;
    for(int i=0;i<s.length();i++)
    {
        map<char,char>::iterator it=m.find(s[i]);
        if(it!=m.end())
            s[i]=it->second;
    }
    printf("%s",s.c_str());
}