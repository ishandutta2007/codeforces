#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
using namespace std;
string s;
int main()
{
    int per=0,ans=0;
    while(getline(cin,s))
    {
        if(s[0]=='+')	per++;
        if(s[0]=='-')	per--;
        else 
        {
            for(int i=0;i<s.length();i++)
            {
                if(s[i]==':')
                {
                    ans+=per*(s.length()-i-1);
                    break;
                }
            }
        }
    }
    printf("%d\n",ans);
}