#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<string>
#include<cstring>
#include<cassert>
#include<ctime>
#include<vector>
#include<list>
#include<stack>
#include<deque>
#include<queue>
#include<map>
#include<utility>
#include<set>
#include<algorithm>

using namespace std;
typedef long long lint;
typedef long double ldb;

#define X first
#define Y second
#define F(i, l, r) for(auto i = l; i != r; i++)
#define Df(i, l, r) for(auto i = l; i != r; i--)
#define pb push_back
#define rs resize
#define mk make_pair
#define asg assign
#define all(x) x.begin(),x.end()
#define ret return
#define cont continue
#define brk break
#define ins insert
#define era erase

const int MAXC = 1e5 + 10;

int n, k;
vector<int> a, cnt;
set<int, greater<int> > sm;
set<int> s;
map<int, int> mp, rmp;

int main(){
    scanf("%d%d", &n, &k);
    a.rs(n); cnt.rs(MAXC); cnt.asg(MAXC, 0);
    F(i, 0, n){
        scanf("%d", &a[i]);
        s.ins(a[i]);
    }
    int gt = 0;
    while(!s.empty()){
        mp[*s.begin()] = gt;
        rmp[gt] = *s.begin();
        gt++;
        s.era(s.begin());
    }
    F(i, 0, n)
        a[i] = mp[a[i]];
    F(i, 0, k){
        cnt[a[i]]++;
        if(cnt[a[i]] == 1)
            sm.ins(a[i]);
        if(cnt[a[i]] == 2)
            sm.era(a[i]);
    }
    if(sm.empty())
        printf("Nothing\n");
    else
        printf("%d\n", rmp[*sm.begin()]);
    int l = 1, r = k;
    while(r < n){
        cnt[a[l - 1]]--;
        cnt[a[r]]++;
        if(cnt[a[l - 1]] == 0)
            sm.era(a[l - 1]);
        if(cnt[a[r]] == 2)
            sm.era(a[r]);
        if(cnt[a[l - 1]] == 1)
            sm.ins(a[l - 1]);
        if(cnt[a[r]] == 1)
            sm.ins(a[r]);
        if(sm.empty())
            printf("Nothing\n");
        else
            printf("%d\n", rmp[*sm.begin()]);
        l++; r++;
    }
    ret 0;
}