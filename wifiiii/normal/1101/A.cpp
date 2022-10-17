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
const int mod = 1e9+7;

int main()
{
    int q;
    cin>>q;
    while(q--)
    {
        ll l,r,d;
        cin>>l>>r>>d;
        if(d<l) cout<<d<<endl;
        else
        {
            cout<<d*(r/d)+d<<endl;
        }
    }
}