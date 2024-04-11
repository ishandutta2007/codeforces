#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>

#define F(i, l, r) for(auto i = l; i != r; i++)
#define Df(i, l, r) for(auto i = l; i != r; i--)
#define rs resize
#define asg assign
#define mk make_pair
#define all(x) x.begin(),x.end()
#define pb push_back
#define ret return
#define X first
#define Y second

using namespace std;
typedef long long lint;

queue<int> q;
vector<lint> s, l, ans;
int n, b;
int sz = 0;
lint cb = 0;

int main(){
    scanf("%d%d", &n, &b);
    l.rs(n); s.rs(n);
    ans.rs(n); ans.asg(n, -1);
    F(i, 0, n){
        int t, d;
        scanf("%d%d", &t, &d);
        s[i] = t; l[i] = d;
        while(!q.empty() && max(cb, s[q.front()]) + l[q.front()] <= t){
            cb = max(cb, s[q.front()]) + l[q.front()];
            ans[q.front()] = cb;
            sz--;
            q.pop();
        }
        if(sz == b + 1)
            continue;
        q.push(i);
        sz++;
    }
    while(!q.empty()){
        cb = max(cb, s[q.front()]) + l[q.front()];
        ans[q.front()] = cb;
        sz--;
        q.pop();
    }
    F(i, 0, n)
        printf("%I64d ", ans[i]);
    ret 0;
}