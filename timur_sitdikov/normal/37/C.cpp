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

struct vert
{
    int len, tmp;
    string str;
    int next[2];
};

bool operator < (const vert & a, const vert & b)
{
    if (a.len !=b.len)
        return a.len>b.len;
    return a.tmp<b.tmp;
}

set<vert> st;
vector<vert> vc;
int llen[1005], used[1005];
vector<string> ans;

void dfs(int s, string tmp)
{
    if (!s)
    {
        ans.pb(tmp);
        return;
    }
    string cur=tmp+vc[s].str;
    dfs(vc[s].next[0], cur);
    if (vc[s].next[1])
        dfs(vc[s].next[1], cur);
}

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, i, j, a, t=0;
    cin >> n;
    vert tmp;
    tmp.str="";
    tmp.next[0]=tmp.next[1]=0;
    for(i=0; i<n; i++)
    {
        t++;
        cin >> a;
        llen[i]=a;
        tmp.len=a;
        tmp.tmp=t;
        st.insert(tmp);
    }
    set<vert>::iterator it, it1;
    vc.pb(tmp);
    while(st.size()>1)
    {
        t++;
        it=st.begin();
        it1=it;
        it1++;
        if (!(it1->len ))
        {
            printf("NO");
            return 0;
        }
        it->str.pb('0');
        it1->str.pb('1');
        for(; it->len>it1->len; )
        {
            it->str.pb('0');
            it->len--;
        }
        vc.push_back(*it1);
        vc.push_back(*it);
        tmp.len=it->len-1;
        tmp.next[0]=vc.size()-2;
        tmp.next[1]=vc.size()-1;
        tmp.tmp=t;
        st.erase(it);
        st.erase(it1);
        st.insert(tmp);     
    }
    it=st.begin();
    tmp=*it;
    for(; tmp.len>0; tmp.len--)
        tmp.str.pb('0');
    vc.pb(tmp);
    dfs(vc.size()-1, "");
    printf("YES\n");
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            if (!used[j] && ans[j].length()==llen[i])
            {
                cout << ans[j] << endl;
                used[j]=1;
                break;
            }
}