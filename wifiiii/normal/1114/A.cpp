#include<iostream>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
#define pb push_back
#define clr(i) memset(i,0,sizeof(i))

typedef pair<int,int> pii;
typedef long long ll;
typedef vector<int> vec;

int main()
{
    int x,y,z;cin>>x>>y>>z;
    int a,b,c;cin>>a>>b>>c;
    int ok = 1;
    if(x>a)
    {
        cout << "NO\n";
        return 0;
    }
    a -= x;
    if(y>a+b)
    {
        cout << "NO\n";
        return 0;
    }
    if(y+z>a+b+c)
    {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
}