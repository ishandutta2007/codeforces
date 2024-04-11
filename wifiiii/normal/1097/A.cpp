#include<iostream>
#include<map>
#include<vector>
#include<cstring>
#include<string>
#include<stdio.h>
#include<queue>
#include<algorithm>
#include<set>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;

int main()
{
    string s;
    cin >> s;
    string ss[6];
    for(int i=1;i<=5;++i) cin>>ss[i];
    for(int i=1;i<=5;++i)
    {
        if(ss[i][0]==s[0]||ss[i][1]==s[1]) {cout<<"YES\n";return 0;}
    }
    cout<<"NO\n";

}