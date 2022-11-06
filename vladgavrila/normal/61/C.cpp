#include <cstdio>
#include <string>
#include <iostream>
#include <map>

using namespace std;

int n, m, b1, b2;
char c1, c2, c3;
long long nr;
string cs, o;
map<int, char> mp;
map<char, int> mpinv;

long long convert_to10(int baza, string s)
{
    long long  sol=0;

    for(int i=0; i<s.size(); ++i)
        sol=sol*baza+mpinv[s[i]];

    return sol;
}

string convertRoman(long long nr)
{
    string sol="";

    if(nr%10<4)
        for(int i=0; i<nr%10; ++i)
            sol="I"+sol;
    else
    if(nr%10==4)
        sol="IV"+sol;
    else
    if(nr%10<9)
    {
        for(int i=0; i<nr%10-5; ++i)
            sol="I"+sol;
        sol="V"+sol;
    }
    else
        sol="IX"+sol;

    nr/=10;

    if(nr%10<4)
        for(int i=0; i<nr%10; ++i)
            sol="X"+sol;
    else
    if(nr%10==4)
        sol="XL"+sol;
    else
    if(nr%10<9)
    {
        for(int i=0; i<nr%10-5; ++i)
            sol="X"+sol;
        sol="L"+sol;
    }
    else
        sol="XC"+sol;

    nr/=10;

    if(nr%10<4)
        for(int i=0; i<nr%10; ++i)
            sol="C"+sol;
    else
    if(nr%10==4)
        sol="CD"+sol;
    else
    if(nr%10<9)
    {
        for(int i=0; i<nr%10-5; ++i)
            sol="C"+sol;
        sol="D"+sol;
    }
    else
        sol="CM"+sol;

    nr/=10;

    for(int i=0; i<nr%10; ++i)
        sol="M"+sol;

    return sol;
}

string convert_10to(int baza, long long nr)
{
    if(baza==0)
        return convertRoman(nr);

    string sol="";
    if(nr==0)
        return "0";

    while(nr>0)
    {
        sol=mp[nr%baza]+sol;
        nr=nr/baza;
    }

    return sol;
}

int main()
{
  //  freopen("data.in", "r", stdin);
 //   freopen("data.out", "w", stdout);

    cin>>b1>>cs;

    for(int i=0; i<10; ++i)
    {
        mp[i]='0'+i;
        mpinv['0'+i]=i;
    }

    for(int i=10; i<=26; ++i)
    {
        mp[i]='A'-10+i;
        mpinv['A'-10+i]=i;
    }

    if(cs!="R")
    {
        for(int i=0; i<cs.size(); ++i)
            b2=b2*10+cs[i]-'0';
    }
    cin>>o;

  //  cout<<convert_to10(b1, o);

    cout<<convert_10to(b2, convert_to10(b1, o))<<"\n";

    return 0;
}