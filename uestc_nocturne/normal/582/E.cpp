/*
Author: elfness@UESTC
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;
typedef long long LL;
const int V=510;
const int P=1000000007;
void tf(int *a,int l,int r)
{
    if(l+1!=r)
    {
        int mid=(l+r)/2;
        tf(a,l,mid);
        tf(a,mid,r);
        for(int i=0;i<mid-l;i++)
        a[l+i]+=a[mid+i], a[l+i] %= P;
    }
}
void utf(int *a,int l,int r)
{
    if(l+1!=r)
    {
        int mid=(l+r)/2;
        for(int i=0;i<mid-l;i++)
        {a[l+i]-=a[mid+i]; if(a[l+i] < 0) a[l+i] += P;}
        utf(a,l,mid);
        utf(a,mid,r);
    }
}

void tf1(int *a,int l,int r)
{
    if(l+1!=r)
    {
        int mid=(l+r)/2;
        tf1(a,l,mid);
        tf1(a,mid,r);
        for(int i=0;i<mid-l;i++)
        {a[mid+i]+=a[l+i]; if(a[mid+i] >=P) a[mid+i] -= P;}
    }
}
void utf1(int *a,int l,int r)
{
    if(l+1!=r)
    {
        int mid=(l+r)/2;
        for(int i=0;i<mid-l;i++)
        {a[mid+i]-=a[l+i]; if(a[mid+i] < 0)a[mid+i] += P;}
        utf1(a,l,mid);
        utf1(a,mid,r);
    }
}
char s[V];
int dp[V][1<<16];
int val[30][30], ret[30], n, m, idx, can[120];
int S[V];
int L[1<<16], R[1<<16], tmp[1<<16];
map<char, int> mp;
int dfs(int l, int r, int dep)
{
    int id = idx++;
    //printf("%d %d %d  ", id, l, r);
    //for(int i = l; i <= r; ++i) printf("%c", s[i]);puts("");
    memset(dp[id], 0, sizeof(dp[id]));
    if(l == r)
    {
        if(s[l] == '?')
        for(int i = 0; i < 8; ++i)
        can[i] = 1;
        else
        {
            for(int i = 0; i < 8; ++i)
            can[i] = 0;
            can[mp[s[l]]] = 1;
        }
        for(int i = 0; i < 4; ++i)
        {
            if(!can[i]) continue;
            int st = 0;
            for(int j = 0; j < m; ++j)
            {
                if(val[j][i] == 1) st |= (1 << j);
            }
            dp[id][st] += 1;
        }
        for(int i = 4; i < 8; ++i)
        {
            if(!can[i]) continue;
            int st = 0;
            for(int j = 0; j < m; ++j)
            {
                if(val[j][i - 4] == 0) st |= (1 << j);
            }
            dp[id][st] += 1;
        }
        //for(int i = 0; i < 8; ++i) printf("%d ", can[i]);puts("");
        //for(int i = 0; i < (1<<m); ++i)printf("%d ", dp[id][i]);puts("");
        return id;
    }
    int sn = 0;
    int mid = -1;
    for(int i = l; i <= r; ++i)
    {
        if(s[i] == '(') sn++;
        else if(s[i] == ')') sn--;
        if(sn == 0 && i != l) {mid = i + 1; break;}
    }
    //printf("%d %c\n", mid, s[mid]);
    int lson = dfs(l + 1, mid - 2, dep + 1);
    int rson = dfs(mid + 2, r - 1, dep + 1);
    if(s[mid] != '|')
    {
        for(int i = 0; i < (1<<m); ++i)
        L[i] = dp[lson][i];
        for(int i = 0; i < (1<<m); ++i)
        R[i] = dp[rson][i];
        /*
        if(dep == 2 && r <= 44)
        {
            puts("L");
            for(int i = 0; i < (1 << m); ++i)
            if(L[i] != 0) {for(int j = 0; j < m; ++j)
            if(i & (1 << j))printf("1 ");
            else printf("0 ");puts("");}
            puts("");
            puts("R");
            for(int i = 0; i < (1 << m); ++i)
            if(R[i] != 0) {for(int j = 0; j < m; ++j)
            if(i & (1 << j))printf("1 ");
            else printf("0 ");puts("");}
            puts("");
        }
        */
        //for(int i = 0; i < (1<<m); ++i)printf("%d ", L[i]);puts("");
        //for(int i = 0; i < (1<<m); ++i)printf("%d ", R[i]);puts("");
        tf(L, 0, (1<<m));
        tf(R, 0, (1<<m));
        for(int i = 0; i < (1<<m); ++i)
        tmp[i] = (LL)L[i] * R[i] % P;
        utf(tmp, 0, (1<<m));
        /*
        if(dep == 2 && r <= 44)
        {
            puts("Tmp");
            for(int i = 0; i < (1 << m); ++i)
            if(tmp[i] != 0) {for(int j = 0; j < m; ++j)
            if(i & (1 << j))printf("1 ");
            else printf("0 ");puts("");}
            puts("");
        }
        */
        //for(int i = 0; i < (1<<m); ++i)printf("%d ", tmp[i]);puts("");
        for(int i = 0; i < (1<<m); ++i)
        dp[id][i] = (dp[id][i] + tmp[i]) % P;
    }
    if(s[mid] != '&')
    {
        for(int i = 0; i < (1<<m); ++i)
        L[i] = dp[lson][i];
        for(int i = 0; i < (1<<m); ++i)
        R[i] = dp[rson][i];
        //for(int i = 0; i < (1<<m); ++i)printf("%d ", L[i]);puts("");
        //for(int i = 0; i < (1<<m); ++i)printf("%d ", R[i]);puts("");
        tf1(L, 0, (1<<m));
        tf1(R, 0, (1<<m));
        for(int i = 0; i < (1<<m); ++i)
        tmp[i] = (LL)L[i] * R[i] % P;
        utf1(tmp, 0, (1<<m));
        //for(int i = 0; i < (1<<m); ++i)printf("%d ", tmp[i]);puts("");
        for(int i = 0; i < (1<<m); ++i)
        dp[id][i] = (dp[id][i] + tmp[i]) % P;
    }
    /*
    if(dep == 2 && r < 61)
    {
        printf("%d %d %d   ", id, l, r);
        for(int i = l; i <= r; ++i) printf("%c", s[i]);puts("");
        for(int i = 0; i < (1 << m); ++i)
        if(dp[id][i] != 0) {for(int j = 0; j < m; ++j)
        if(i & (1 << j))printf("1 ");
        else printf("0 ");puts("");}
        puts("");
    }
    */
    return id;
}
int main()
{
    for(int i = 0; i < 4; ++i) mp['A' + i] = i;
    for(int i = 0; i < 4; ++i) mp['a' + i] = i + 4;
    while(~scanf("%s", s))
    {
        int L = strlen(s);
        scanf("%d", &m);
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < 4; ++j)
            scanf("%d", &val[i][j]);
            scanf("%d", &ret[i]);
        }
        memset(dp, 0, sizeof(dp));
        idx = 0;
        int root = dfs(0, L - 1, 0);
        int ansst = 0;
        for(int i = 0; i < m; ++i)
        if(ret[i] == 1) ansst |= (1<<i);
        /*
        printf("%d\n", ansst);
        for(int i = 0; i < (1 << m); ++i)
        if(dp[root][i] != 0) {for(int j = 0; j < m; ++j)
        if(i & (1 << j))printf("1 ");
        else printf("0 ");puts("");}
        puts("");
        */
        printf("%d\n", dp[root][ansst]);
    }
}

/*

?
2
1 0 1 0 1
0 1 1 0 1

(A)?(?)
1
1 1 0 0 0

((?)&(?))|((?)&(?))
0

b
1
1 0 1 1 1

((((((d)?(?))|((((B)|(?))?(?))?(?)))?(?))&(a))?((D)?((A)&(?))))?(((?)?(?))?((((?)?(?))?((?)?(?)))?((?)?(?))))
12
0 1 1 1 0
0 0 0 1 0
1 0 0 0 0
0 0 0 0 0
1 1 0 0 0
0 0 1 0 0
1 1 1 1 0
1 0 1 0 0
0 1 0 1 0
0 0 1 1 0
0 1 0 0 0
1 1 0 1 0


*/