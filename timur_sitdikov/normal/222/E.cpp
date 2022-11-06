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

const int al_sz=52;
const long long mod=1000000007;
int m;
struct matrix
{
    long long m[al_sz][al_sz];
    int sz;
    matrix(int sz)
    {
        for(int i=0; i<al_sz; i++)
            for(int j=0; j<al_sz; j++)
                m[i][j]=0;
        this->sz=sz;
    }
};

matrix operator *(matrix &a, matrix &b)
{
    matrix ans(m);
    int i, j, k;
    for(i=0; i<m; i++)
        for(j=0; j<m; j++)
            for(k=0; k<m; k++)
                ans.m[i][j]=(ans.m[i][j]+a.m[i][k]*b.m[k][j])%mod;
    return ans;
}

matrix pow_mod(matrix &a, long long st, long long mod)
{
    matrix ans(m), tmp(m);
    int i;
    for(i=0; i<m; i++)
        ans.m[i][i]=1;
    tmp=a;
    for(; st; st/=2)
    {
        if (st&1)
            ans=ans*tmp;
        tmp=tmp*tmp;
    }
    return ans;
}

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    long long n, ans;
    int k, i, j, v1, v2;    
    string s;
    cin >> n >> m >> k;
    matrix a(m), b(m);
    for(i=0; i<m; i++)
        for(j=0; j<m; j++)
            a.m[i][j]=1;
    for(i=0; i<k; i++)
    {
        cin >> s;
        if (s[0]>='a')
            v1=s[0]-'a';
        else
            v1=s[0]-'A'+26;
        if (s[1]>='a')
            v2=s[1]-'a';
        else
            v2=s[1]-'A'+26;
        a.m[v1][v2]=0;
    }
    b=pow_mod(a, n-1, mod);
    ans=0;
    for(i=0; i<m; i++)
        for(j=0; j<m; j++)
            ans=(ans+b.m[i][j])%mod;
    cout << ans;    
}