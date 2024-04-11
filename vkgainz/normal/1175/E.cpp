#include <bits/stdc++.h>
using namespace std;
#define ll long long

int tab[500001][20];
vector<int> intervals[500001];
int main(){
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        int l,r; cin >> l >> r;
        intervals[r].push_back(l);
    }
    int leastL = 500000;
    for(int i=500000;i>=0;i--){
        for(int j : intervals[i]){
            leastL = min(leastL,j);
        }
        tab[i][0] = leastL;
    }
    
    for(int j=1;j<20;j++){
        for(int i=0;i<=500000;i++)
            tab[i][j] = tab[tab[i][j-1]][j-1];
    }
    for(int i=0;i<m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        if(tab[y][19]>x)
            cout << -1 << endl;
        else{
            if(tab[y][0]<=x){
                cout << 1 << endl;
                continue;
            }
            int ans = 0;
            for(int j=19;j>=0;j--){
                if(tab[y][j]>x){
                    y = tab[y][j];
                    ans+=1<<j;
                }
            }
            ++ans;
            printf("%d\n",ans);
        }
    }
}