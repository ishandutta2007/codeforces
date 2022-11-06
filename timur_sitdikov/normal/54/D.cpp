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

char s[300], good[300], word[300], mp[300], c;

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif  
    int n, i, j, k, l, f;
    scanf("%d %d %s %s", &n, &k, &word, &mp);
    l=strlen(word);
    for(i=0; i<n-l+1; i++)
        if (mp[i]=='1')
        {
            for(j=0; j<l; j++)
            {
                if (s[i+j] && s[i+j]!=word[j])
                {
                    printf("No solution");
                    return 0;
                }
                s[i+j]=word[j];
            }
        }
    for(i=0; i<n-l+1; i++)
        if (mp[i]=='0')
        {
            f=0;
            for(j=0; j<l; j++)
                if (s[i+j]!=word[j])
                {
                    f=1;
                    break;
                }
            if (!f)
            {
                printf("No solution");
                return 0;
            }
        }
    f=0;
    for(i=0; i<n; i++)
        if (!s[i])
        {
            f=1;
            break;
        }
    if (!f)
    {
        printf("%s", s);
        return 0;
    }
    
    for(i=0; i<l; i++)
        good[word[i]]=1;
    for(i='a'; i<'a'+k; i++)
        if (!good[i])
            c=i;
    if (!c)
    {
        for(i=0; i<l-1; i++)
            if (word[i]!=word[i+1])
            {
                c=word[i];
                break;
            }
    }
    if (!c)
    {
        printf("No solution");
        return 0;
    }
    for(i=0; i<n; i++)
        if (!s[i])
            s[i]=c;
    printf("%s", s);
}