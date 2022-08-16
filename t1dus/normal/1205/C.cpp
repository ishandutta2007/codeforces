#include<bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i ++)
#define FOR(i,a,b) for(int i = a; i < b; i ++)

int n;
int a[55][55];

bool valid(int i,int j){
    if(i < 1 or i > n or j < 1 or j > n) return false;
    return a[i][j] == -1;
}

int query(int x1,int y1,int x2,int y2){
    if(x2 < x1 or y2 < y1){
        cout << "? " << x2 << " " << y2 << " " << x1 << " " << y1 << endl;
    }
    else{
        cout << "? " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;    
    }
    int q; cin >> q;
    return q;
}

void dfs(int i,int j);

void get(int x1,int y1,int x2,int y2){
    if(!valid(x2,y2)) return;
    if(query(x1,y1,x2,y2)) a[x2][y2] = a[x1][y1];
    else a[x2][y2] = 1-a[x1][y1];
    dfs(x2,y2);
}

void dfs(int i,int j){
    get(i,j,i+2,j);
    get(i,j,i,j+2);
    get(i,j,i+1,j+1);
    get(i,j,i-2,j);
    get(i,j,i,j-2);
    get(i,j,i-1,j-1);

}

signed main(){
    cin >> n;
    REP(i,n+1) REP(j,n+1) a[i][j] = -1;
    a[1][1] = 1;
    a[n][n] = 0;
    dfs(1,1);
    int ind;
    for(int i = 1; i < n; i += 2){
        if(a[i][i] == 1 and a[i+2][i+2] == 0){
            ind = i;
            break;
        }
    }
    a[1][2] = 0;
    dfs(1,2);
    bool flag = 0;
    
    bool cur = 0;
    if(a[ind+1][ind] == a[ind+2][ind]) cur = 1;
    if(a[ind+1][ind] == a[ind+1][ind+1]) cur = 1;
    if(a[ind][ind+1] == a[ind+1][ind+1]) cur = 1;
    cur &= (a[ind][ind] == a[ind+2][ind+1]);
    if(query(ind,ind,ind+2,ind+1) != cur) flag = 1;

    cur = 0;
    if(a[ind+1][ind] == a[ind+1][ind+1]) cur = 1;
    if(a[ind][ind+1] == a[ind+1][ind+1]) cur = 1;
    if(a[ind][ind+1] == a[ind][ind+2]) cur = 1;
    cur &= (a[ind][ind] == a[ind+1][ind+2]);
    if(query(ind,ind,ind+1,ind+2) != cur) flag = 1;

    cur = 0;
    if(a[ind+1][ind+1] == a[ind+2][ind+1]) cur = 1;
    if(a[ind+1][ind+1] == a[ind+1][ind+2]) cur = 1;
    if(a[ind][ind+2] == a[ind+1][ind+2]) cur = 1;
    cur &= (a[ind][ind+1] == a[ind+2][ind+2]);
    if(query(ind,ind+1,ind+2,ind+2) != cur) flag = 1;

    if(flag){
        FOR(i,1,n+1){
            FOR(j,1,n+1){
                if((i+j)%2) a[i][j] = 1-a[i][j];
            }
        }
    }
    cout << "!" << endl;
    FOR(i,1,n+1){
        FOR(j,1,n+1){
            cout << a[i][j];
        }
        cout << endl;
    }
}