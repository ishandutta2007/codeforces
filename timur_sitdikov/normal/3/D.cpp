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
using namespace std;

int a[50005], b[50005];
char s[50005];
set <pair<int, int> > st;

int main()
{   
    /*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    int n, m, top=0, dif=0, i,  ind;
    long long ans=0;
    scanf("%s", &s);
    n=strlen(s);
    for(i=0; i<n; i++) 
        if (s[i]=='?') scanf("%d %d", &a[i], &b[i]);
    for(i=0; i<n; i++)
    {
        if (s[i]=='(') dif++;
        if (s[i]=='?')
        {
            st.insert(make_pair(a[i]-b[i], i));
            s[i]=')';
            ans+=b[i];
        }
        if (s[i]==')') 
        {
            dif--;
            if (dif<0)
            {
                if (st.empty()) {printf("-1"); return 0;}
                ind=st.begin()->second;
                st.erase(st.begin());
                s[ind]='(';
                ans+=a[ind]-b[ind];
                dif+=2;
            }
        }
    }
    if (dif>0) {printf("-1"); return 0;}
    printf("%I64d\n%s", ans, s);
}