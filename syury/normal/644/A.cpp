#include<cstdio>
#include<vector>
#include<algorithm>

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

int n, a, b, c1 = 0, c2 = 0, s;
vector<vector<int> > ans;
vector<vector<char> > col;

void paint(int x, int y){
    col[x][y] = false;
    if(y + 2 < b){
        paint(x, y + 2);
        ret;
    }
    if(x + 1 < a){
        if(y % 2 == 0){
            if(b != 1){
                paint(x + 1, 1); ret;
            }
            if(x + 2 < a)
                paint(x + 2, 0);
            ret;
        }
        else{
            paint(x + 1, 0);
        }
    }
}

int main(){
    scanf("%d%d%d", &n, &a, &b);
    if(a * b < n){
        printf("-1"); ret 0;
    }
    int x = (n%2 == 0) ? (n - 1) : n, y = (n%2 == 0) ? n : (n - 1);
    ans.rs(a); col.rs(a);
    F(i, 0, a){
        ans[i].rs(b); ans[i].asg(b, 0);
        col[i].rs(b); col[i].asg(b, true);
    }
    paint(0, 0);
    s = a * b;
    int currx = 1, curry = 2;
    F(i, 0, a){
        F(j, 0, b){
            if(col[i][j] && curry <= y){
                ans[i][j] = curry; curry += 2;
            }
            if(!col[i][j] && currx <= x){
                ans[i][j] = currx; currx += 2;
            }
        }
    }
    if(currx <= x || curry <= y){
        printf("-1"); ret 0;
    }
    F(i, 0, a){
        F(j, 0, b){
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
    ret 0;
}