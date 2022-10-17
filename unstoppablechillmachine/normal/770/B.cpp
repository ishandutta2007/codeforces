#include <bits/stdc++.h>


using namespace std;

typedef long long ll;
typedef long double ld;

#define f first
#define sec second
#define itn int
#define fro for

ll j;
bool t=true;
string s,s1,str;

bool check(string s)
{
    if (s.size()!=str.size()) return s.size()<str.size();
    int j=0;
    while (j<s.size() && s[j]==str[j]) j++;
    if (j==s.size()) return true;
    return s[j]<str[j];
}



int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);

    cin>>str;
    s="";
    while (t)
    {
        t=false;
        s1.insert(s1.begin(),'9');
        for (int i=9;i>=0;i--)
        {
            s1[0]=i+48;
            if (check(s1))
            {
                t=true;
                break;
            }
        }
        if (t) s=s1;
    }



    t=true;

    while (t && s[0]<'9')
    {
        t=false;
        for (int i=s.size()-1;i>0;i--)
        {
            s1=s;
            s1[0]++;
            s1[i]--;
            //cout<<s1<<endl;
            if (check(s1))
            {
                t=true;
                break;
            }
        }
        if (t) s=s1;
    }

    j=0;
    while (j<s.size() && s[j]=='0') j++;

    fro (int i=j;j<s.size();j++) cout<<s[j];

    return 0;
}