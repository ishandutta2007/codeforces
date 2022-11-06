#include <cstdio>
#include <string>
#include <map>
#include <iostream>

using namespace std;

int n, m;
map<string, int> mp;
string s, s1, s2, s3;

string convert(string s)
{
    string sol="";
    for(int i=0; i<s.size(); ++i)
    {
        if((s[i]>='a' && s[i]<='z')||(s[i]>='A' && s[i]<='Z'))
        {
            if(s[i]>='a')
                sol+=s[i]-'a'+'A';
            else
                sol+=s[i];
        }
    }
    return sol;
}


int main()
{
   // freopen("data.in", "r", stdin);
  //  freopen("data.out", "w", stdout);

    getline(cin, s1);
    getline(cin, s2);
    getline(cin, s3);

    s1=convert(s1);
    s2=convert(s2);
    s3=convert(s3);

    mp[s1+s2+s3]=1;
    mp[s1+s3+s2]=1;
    mp[s2+s1+s3]=1;
    mp[s2+s3+s1]=1;
    mp[s3+s1+s2]=1;
    mp[s3+s2+s1]=1;

    scanf("%d\n", &n);
    while(n--)
    {
        getline(cin, s);
        if(mp[convert(s)]==1)
            printf("ACC\n");
        else
            printf("WA\n");
    }

    return 0;
}