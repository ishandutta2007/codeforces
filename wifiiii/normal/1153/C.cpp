#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <unordered_map>
using namespace std;
typedef long long ll;

int main()
{
    int n;cin>>n;
    string s;
    cin>>s;
    if(s.size() % 2)
    {
        cout << ":(" << endl;
        return 0;
    }
    int cnt = 0;
    for(int i=0;i<s.size();++i)
    {
        if(s[i]=='(') cnt++;
    }
    int ned = s.size()/2 - cnt;
    if(ned<0)
    {
        cout << ":(" << endl;
        return 0;
    }
    for(int i=0;i<s.size();++i)
    {
        if(s[i]=='?') s[i]='(',ned--;
        if(ned==0) break;
    }
    if(ned>0)
    {
        cout << ":(" << endl;
        return 0;
    }
    for(int i=0;i<s.size();++i)
    {
        if(s[i]=='?') s[i]=')';
    }
    int ct = 0;
    for(int i=0;i<s.size();++i)
    {
        if(s[i]=='(') ct++;
        else ct--;
        if(i==s.size()-1) break;
        if(ct<=0)
        {
            cout << ":(" << endl;
            return 0;
        }
    }
    cout << s << endl;
}