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

char s[1000005];
int ans[1000005];
int main()
{
    scanf("%s",s+1);
    int len = strlen(s+1);
    int st = 1, ed = len;
    for(int i=1;i<=len;++i)
    {
        if(s[i]=='l') ans[ed--]=i;
        else ans[st++]=i;
    }
    for(int i=1;i<=len;++i) cout<<ans[i]<<endl;
}