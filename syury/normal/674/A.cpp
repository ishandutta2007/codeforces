#include<bits/stdc++.h>

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
#define y1 adjf

int n;
vector<int> col;
vector<int> ans;
vector<lint> tot;

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    scanf("%d", &n);
    col.rs(n);
    ans.rs(n);
    tot.rs(n);
    tot.asg(n, 0);
    ans.asg(n, 0);
    F(i, 0, n){
        scanf("%d", &col[i]);
        col[i]--;
    }
    F(i, 0, n){
        ans.asg(n, 0);
        int curr = 0;
        F(j, i, n){
            ans[col[j]]++;
            if(ans[col[j]] > ans[curr] || (ans[col[j]] == ans[curr] && col[j] < curr))
                curr = col[j];
            tot[curr]++;
        }
    }
    F(i, 0, n)
        printf("%lld ", tot[i]);
    ret 0;
}