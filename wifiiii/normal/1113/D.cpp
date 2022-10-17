#include<iostream>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<cmath>
#include<algorithm>
#include<set>
#include<ctime>
using namespace std;
#define pb push_back
#define clr(i) memset(i,0,sizeof(i))

typedef long long ll;
typedef vector<int> vec;
typedef pair<ll,ll> pii;

int ispal(string s)
{
    int i=0,j=s.size()-1;
    while(i<j) if(s[i++]!=s[j--]) return 0;
    return 1;
}

int cmp(string s1,string s2)
{
    int n = s1.size();
    for(int i=0;i<n;++i) if(s1[i]!=s2[i]) return 1;
    return 0;
}
int solve(string s)
{
    int n = s.size();
    for(int i=1;i<n;++i)
    {
        string s2 = s.substr(i,n-i) + s.substr(0,i);
        if(ispal(s2)&&cmp(s,s2)) return 1;
    }
    return 2;
}
int main()
{
    string s;
    cin>>s;
    int n = s.size();
    int ok = 0;
    for(int i=0;i<n;++i)
    {
        if(n%2&&i==n/2) continue;
        if(s[i]!=s[0]) ok=1;
    }
    if(!ok)
    {
        cout<<"Impossible"<<endl;
        return 0;
    }
    cout << solve(s) << endl;
}