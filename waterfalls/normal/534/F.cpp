#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int n,m;
int row[5];
int col[20];
int cur[5];
int curl[5];
int curr[5];
int cnt[32];
char prev[2][11][6][6][6][6][6][32];
char sol[5][20];
vector<int> has[4];

void solve(int on, int finish, int last, int which) {
    if (on>=finish) return;
    for (int k=0;k<has[col[on]].size();k++) {
        int i = has[col[on]][k];
        for (int j=0;j<5;j++) if ((i&(1<<j)) && (last&(1<<j))==0) cur[j]+=1;
        if (prev[which][on][cur[0]][cur[1]][cur[2]][cur[3]][cur[4]][i]==-1) {
            prev[which][on][cur[0]][cur[1]][cur[2]][cur[3]][cur[4]][i] = last;
            solve(on+1,finish,i,which);
        }
        for (int j=0;j<5;j++) if ((i&(1<<j)) && (last&(1<<j))==0) cur[j]-=1;
    }
}

void complete(int where, int put, int diff, int which, int last) {
    if (where<0) return;
    for (int i=0;i<5;i++) sol[i][put] = (last&(1<<i)) ? '*' : '.';
    int bef = prev[which][where][cur[0]][cur[1]][cur[2]][cur[3]][cur[4]][last];
    for (int i=0;i<5;i++) if ((last&(1<<i)) && (bef&(1<<i))==0) cur[i]-=1;
    complete(where-1,put+diff,diff,which,bef);
}

bool test(int l, int r, int on) {
    if (on==5) {
        for (int i=0;i<5;i++) curr[i] = row[i]-curl[i]+((l&r&(1<<i))!=0);
        for (int i=0;i<5;i++) if (curr[i]<0 || curr[i]>5) return false;
        if (prev[0][m/2-1][curl[0]][curl[1]][curl[2]][curl[3]][curl[4]][l]==-1) return false;
        if (prev[1][(m+1)/2-1][curr[0]][curr[1]][curr[2]][curr[3]][curr[4]][r]==-1) return false;
        swap(cur,curl);
        complete(m/2-1,m/2-1,-1,0,l);
        swap(cur,curr);
        complete((m+1)/2-1,m/2,1,1,r);
        return true;
    }
    for (int i=0;i<=min(5,row[on]);i++) {
        curl[on] = i;
        if (test(l,r,on+1)) return true;
    }
    return false;
}

int main() {
    for (int i=0;i<32;i++) {
        int j = i;
        while (j) {
            while (j%2==0) j/=2;
            cnt[i]+=1;
            while (j%2==1) j/=2;
        }
        has[cnt[i]].push_back(i);
    }
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++) scanf("%d",&row[i]);
    for (int i=0;i<m;i++) scanf("%d",&col[i]);
    if (m==1) {
        for (int i=0;i<n;i++) printf("%c\n",row[i] ? '*' : '.');
        return 0;
    }
    memset(prev,-1,sizeof prev);
    solve(0,m/2,0,0);
    for (int i=0;i<m/2;i++) swap(col[i],col[m-i-1]);
    solve(0,(m+1)/2,0,1);
    for (int i=0;i<m/2;i++) swap(col[i],col[m-i-1]);
    int found = 0;
    for (int l=0;l<has[col[m/2-1]].size() && !found;l++) for (int r=0;r<has[col[m/2]].size() && !found;r++) {
        if (test(has[col[m/2-1]][l],has[col[m/2]][r],0)) found = 1;
    }
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) printf("%c",sol[i][j]);
        printf("\n");
    }

    return 0;
}