
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
using namespace std;
typedef long long ll;
const int maxn = 2e5+5;

int a[maxn], b[maxn], nxt[maxn], lst[maxn];
int n;
vector<int> ans;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i) scanf("%d",a+i);
    for(int i=1;i<=n;++i)
    {
        int tmp;
        scanf("%d",&tmp);
        ++b[tmp];
    }
    for(int i=0;i<n;++i) nxt[i] = (i+1)%n;
    for(int i=0;i<n;++i) lst[nxt[i]] = i;
    for(int i=1;i<=n;++i)
    {
        for(int j=nxt[lst[(n-a[i])%n]];;j=nxt[j])
        {
            if(b[j])
            {
                --b[j];
                ans.push_back((j+a[i])%n);
                break;
            }
            else
            {
                nxt[lst[j]] = nxt[j];
                lst[nxt[j]] = lst[j];
            }
        }
    }
    for(int i:ans) printf("%d ",i);
}