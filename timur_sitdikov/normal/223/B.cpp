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

string s, t;
const int maxn=200005;
int l[maxn], r[maxn], num[30][maxn];
const int inf=1000000;

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int i, j, l1, l2, tmp;
    cin >> s >> t;
    l1=s.length();
    l2=t.length();
    for(i=0; i<l2; i++)
        num[t[i]-'a'][i]=1;
    for(j=0; j<26; j++)
        for(i=1; i<l2; i++)
            num[j][i]+=num[j][i-1];
    for(i=l1-1, j=l2-1; i>=0 && j>=0; i--)
    {
        if (s[i]==t[j])
        {
            j--;
        }
        r[i]=j+1;
    }
    for(i=0, j=0; i<l1 && j<l2; i++)
    {
        if (s[i]==t[j])
        {
            j++;
        }
        l[i]=j-1;
    }
    for(; i<l1; i++)
        l[i]=l2-1;
    for(i=0; i<l1; i++)
    {
        if (l[i]<r[i])
        {
            printf("No");
            return 0;
        }
        tmp=num[s[i]-'a'][l[i]];
        if (r[i])
            tmp-=num[s[i]-'a'][r[i]-1];
        if (!tmp)
        {
            printf("No");
            return 0;
        }
    }
    printf("Yes");
}