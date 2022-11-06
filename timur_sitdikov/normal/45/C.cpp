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

const int maxn=200010;
char col[maxn];
set <pair<int, int> > st;
int l[maxn], r[maxn], a[maxn];
int num[200];

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, i, tmp;
    cin >> n;
    scanf("%s", &col[1]);
    for(i=1; i<=n; i++)
        cin >> a[i];
    for(i=1; i<=n; i++)
        num[col[i]]++;
    for(i=0; i<=n; i++)
        r[i]=i+1;
    for(i=n+1; i>0; i--)
        l[i]=i-1;
    for(i=1; i<=n; i++)
        if (col[i]+col[i+1]=='B'+'G')
        {
            st.insert(make_pair(abs(a[i]-a[i+1]), i));
        }
    printf("%d\n", min(num['B'], num['G']));
    while(!st.empty())
    {
        tmp=st.begin()->second;
        cout << tmp << " " << r[tmp] << endl;
        st.erase(st.begin());
        if (col[tmp]+col[l[tmp]]=='B'+'G')
            st.erase(make_pair(abs(a[tmp]-a[l[tmp]]), l[tmp] ));
        if (col[r[tmp]]+col[r[r[tmp]]]=='B'+'G')
            st.erase(make_pair(abs(a[r[tmp]]-a[r[r[tmp]]]), r[tmp]));
        if (col[l[tmp]]+col[r[r[tmp]]]=='B'+'G')
            st.insert(make_pair(abs(a[l[tmp]]-a[r[r[tmp]]]), l[tmp]));
        l[r[r[tmp]]]=l[tmp];
        r[l[tmp]]=r[r[tmp]];
    }   
}