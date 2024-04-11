#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <deque>
#include <time.h>
#include <stack>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#define mp make_pair
#define pb push_back
#define PI 3.14159265358979323846
#define MOD 1000000009
typedef long long ll;
using namespace std;
ll x,y,w,l,r,i,j,n,k,k1,k2,d,m,q,max1,amnt,a[200500],b[100500];
string s,t;
multiset <ll> servers;
multiset <ll>::iterator itr;
int main()
{
    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);
    cin >> n >> k;
    for (i = 0; i < k; i++)
        servers.insert(0);
    for (i = 0; i < n; i++)
    {
        scanf("%I64d%I64d",&x,&y);
        itr = servers.begin();
        ll tmp = max((*itr),x);
        tmp += y;
        printf("%I64d\n",tmp);
        servers.erase(itr);
        servers.insert(tmp);
    }
    return 0;
}