#include <iostream>
#include <cstdio>
#include <queue>
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, b, a) for(int i = (b); i >= (a); i--)
#define ll long long
using namespace std;
const int N = 1e6 + 9, inf = 0x3f3f3f3f;
int a[N], n, m;
ll  ans[N], cf[N];
struct node{
    int pl, num;
}z;
deque<node> q;
int main(){
    scanf("%d%d", &m, &n);
    rep(T, 1, m){
        int l, mmax = -inf; scanf("%d", &l);
        rep(i, 1, l) scanf("%d", &a[i]);
        if(2 * l <= n){
            mmax = 0;
            rep(i, 1, l) mmax = max(mmax, a[i]), ans[i] += mmax;
            cf[l+1] += max(mmax, a[l]), cf[n-l+1] -= max(mmax, a[l]);
            mmax = 0;
            per(i, n, n-l+1) mmax = max(mmax, a[i-n+l]), ans[i] += mmax; 
        } 
        else{
        	//if(n == l){ rep(i, 1, n) ans[i] += a[i]; continue; }()
            while(!q.empty()) q.pop_front();
            //rep(i, 1, n-l) mmax = max(mmax, a[i]), ans[i] += max(mmax, 0);
            //ans[n-l+1] += max(mmax, a[n-l+1]);// 
            z.pl = 0, z.num = 0;//mmax=0 
            q.push_back(z);
            rep(i, 1, n){
                z.pl = i, z.num = a[i];
                if(i > l) z.num = 0; 
                while(!q.empty() && q.back().num <= z.num) q.pop_back();
                q.push_back(z);
                while(!q.empty() && i - q.front().pl > n-l) q.pop_front();
                ans[i] += q.front().num;  
            }
            //mmax = -inf;() 
            //per(i, n, l+1) mmax = max(mmax, a[i-n+l]), ans[i] += max(mmax, 0);
        }
    }
    rep(i, 1, n) { cf[i] += cf[i-1]; printf("%lld ", ans[i] + cf[i]); }
    return 0;
}
/*
a[1],a[2]...a[l] 
*/