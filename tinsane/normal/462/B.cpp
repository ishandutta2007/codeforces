#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <deque>
#include <math.h>
#include <iomanip>
#include<map>
#include <string>
#include<list>
#include<stack>
#include<algorithm>
#include <queue>
#include <time.h>
#include<functional>
#include<set>
using namespace std;

#define PI 3.14159265358979323846
#define MIN(a,b) ((a>b)? b : a)
#define MAX(a,b) ((a<b)? b : a)
#define MOD(a) ((a>0)? a : -a)
#define ll long long
#define ld long double
#define ull unsigned long long
#define uint unsigned int
#define MAXINT 1000000010
#define MAXLL 1000000000000000000
#define PII pair<int,int> 
#define PLL pair<ll,ll>
#define VI vector<int> 
#define VVI vector<vector<int>> 
#define V(a) vector<a>
#define _10POW9PLUS7 1000000007 
//  8739
#pragma comment(linker, "/STACK:167772160")

int comp(const void * a, const void* b){
    return (*(ll*)b)-(*(ll*)a);
}

int main(){
    const int alph='Z'-'A'+1;
    ios_base::sync_with_stdio(0);
    ll n,k, mas[alph], ans(0);
    char s[100000];
    scanf("%I64d%I64d%*c", &n, &k);
    for(int i(0); i<n;++i)
        scanf("%c", &s[i]);
    for(int i(0); i<alph;++i)
        mas[i]=0;
    for(int i(0); i<n;++i)
        ++mas[s[i]-'A'];
    qsort(mas, alph, sizeof(ll),comp);
    for(int i(0); i<alph;++i){
        if(mas[i]>=k){
            ans+=k*k;
            break;
        }
        ans+=mas[i]*mas[i];
        k-=mas[i];
    }
    printf("%I64d", ans);
    return 0;
}