//#include <bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<stack>
#include<set>
#include<map>
#include<time.h>
#include<cstdlib>
#include<unordered_map>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=100005;

ll a[5];

int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>a[0]>>a[1]>>a[2];
        sort(a,a+3);
        if(a[0]<a[1])
        {
            a[0]++;
            if(a[2]>a[1])
                a[2]--;
            else
            {
                if(a[1]>a[0])
                {
                    a[1]--;
                    a[2]--;
                }
            }
        }
        else
        {
            if(a[1]<a[2])
            {
                a[0]++;
                a[1]++;
            }
            if(a[2]>a[1])
            a[2]--;
        }
        sort(a,a+3);
        cout<<a[2]-a[1]+a[2]-a[0]+a[1]-a[0]<<endl;
    }
    
    return 0;
}