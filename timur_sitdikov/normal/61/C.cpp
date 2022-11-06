#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <complex>
using namespace std;
#define pb push_back
#define mp make_pair
#define point complex<double>
#define xx first
#define yy second

string get_roman(long long v)
{
    string ans;
    while(v>=1000)
    {
        ans+="M";
        v-=1000;
    }
    while(v>=900)
    {
        ans+="CM";
        v-=900;
    }
    while(v>=500)
    {
        ans+="D";
        v-=500;
    }
    while(v>=400)
    {
        ans+="CD";
        v-=400;
    }
    while(v>=100)
    {
        ans+="C";
        v-=100;
    }
    while(v>=90)
    {
        ans+="XC";
        v-=90;
    }
    while(v>=50)
    {
        ans+="L";
        v-=50;
    }
    while(v>=40)
    {
        ans+="XL";
        v-=40;
    }
    while(v>=10)
    {
        ans+="X";
        v-=10;
    }
    while(v>=9)
    {
        ans+="IX";
        v-=9;
    }
    while(v>=5)
    {
        ans+="V";
        v-=5;
    }
    while(v>=4)
    {
        ans+="IV";
        v-=4;
    }
    while(v>=1)
    {
        ans+="I";
        v-=1;
    }
    return ans;
}

long long get_decimal(string num, long long base)
{
    long long ans = 0;
    for( int i = 0; i < (int)num.length(); i++)
    {
        long long dig = (num[i]<='9'? num[i]-'0': num[i]-'A'+10);
        ans = ans * base + dig;
    }
    return ans;
}

string get_val(long long val, long long base)
{
    string ans;
    for(; val; val/=base)
    {
        long long dig = val%base;
        if (dig<=9)
            ans.pb((char)dig+'0');
        else
            ans.pb((char)dig-10+'A');
    }
    if (ans.empty())
        ans.pb('0');
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    long long a, b, v;
    string s, c;
    cin >> a >> s >> c;
    v = get_decimal(c, a);
    if (s[0]=='R')
        cout << get_roman(v);
    else
    {
        b = s[0]-'0';
        if (s.length()==2)
            b = b * 10 + s[1] - '0';
        cout << get_val(v, b);
    }
}