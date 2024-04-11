#include <bits/stdc++.h>
using namespace std;

char str[100][100];
int n,m;

bool one() {
    int f=1,i,j;
    for(i=0,j=0;j<m;j++) if(str[i][j] == 'P') {
        f=0; break;
    }
    if(f) return true;
    f=1;

    for(i=n-1,j=0;j<m;j++) if(str[i][j] == 'P') {
        f=0; break;
    }
    if(f) return true;
    f=1;

    for(i=0,j=0;i<n;i++) if(str[i][j]=='P') {
        f=0; break;
    }
    if(f) return true;
    f=1;

    for(i=0,j=m-1;i<n;i++) if(str[i][j]=='P') {
        f=0; break;
    }
    if(f) return true;
    return false;
}

bool two() {
    if(str[0][0] =='A' || str[n-1][0] == 'A' || str[0][m-1]=='A' || str[n-1][m-1]=='A') {
        return true;
    } 
    
    for(int i=0;i<n;i++) {
        int f=1;
        for(int j=0;j<m;j++) if(str[i][j] == 'P') {
            f=0; break;
        }
        if(f) return true;
    }
    for(int j=0;j<m;j++) {
        int f=1;
        for(int i=0;i<n;i++) if(str[i][j]=='P') {
            f=0; break;
        }
        if(f) return true;
    }
    return false;
}

bool three() {
    for(int i=0;i<n;i++) if(str[i][0]=='A' || str[i][m-1]=='A') {
        return true;
    }
    for(int j=0;j<m;j++) if(str[0][j]=='A' || str[n-1][j]=='A') {
        return true;
    }
    return false;
}

int main() {
    int test;
    scanf("%d",&test);
    while(test--) {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++) scanf("%s",str[i]);

    
        int f=1;
        for(int i=0;i<n;i++)for(int j=0;j<m;j++) if(str[i][j]=='P') {
            f=0;
            break;
        }
        if(f) puts("0");
        else if(one()) puts("1");
        else if(two()) puts("2");
        else if(three()) puts("3");
        else {
            int f=0;
            for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(str[i][j]=='A') {
                f=1; break;
            }
            if(f) puts("4");
            else puts("MORTAL");
        }
    }
    return 0;
}