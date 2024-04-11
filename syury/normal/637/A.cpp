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

int n;
map<int, int> mp;
map<int, int> last;
int mv = -1, pos = -1, clast = 1e9;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    scanf("%d", &n);
    F(i, 0, n){
        int tmp;
        scanf("%d", &tmp);
        if(mp.count(tmp))
            mp[tmp]++;
        else
            mp.insert(mk(tmp, 1));
        last[tmp] = i;
    }
    F(i, mp.begin(), mp.end()){
        int cp = i->X, cv = i->Y, cl = last[cp];
        if(cv > mv || (cv == mv && cl < clast)){
            mv = cv; pos = cp; clast = cl;
        }
    }
    printf("%d", pos);
    ret 0;
}