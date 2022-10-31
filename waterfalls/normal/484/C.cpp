#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int n,m;
char S_[1000013];
char S2_[1000013];
int jump[20][1000013];

void order(int k, int d) {
    int where = 0;
    for (int i=0;i<d;i++) {
        int cur = i;
        while (cur<k) jump[0][cur] = where++, cur+=d;
    }
    for (int j=1;j<20;j++) for (int i=0;i<k;i++) {
        if (jump[j-1][i]-1==-1 || jump[j-1][jump[j-1][i]-1]-1==-1) jump[j][i] = 0;
        else jump[j][i] = jump[j-1][jump[j-1][i]-1];
    }
}

int go(int where,int num) {
    for (int j=19;j>=0;j--) if (num&(1<<j)) where = jump[j][where]-1;
    return where+1;
}

int main() {
    char* S = S_;
    char* S2 = S2_;
    scanf(" %s%d",S,&m);
    n = strlen(S);
    S2[n] = '\0';
    for (int M=0;M<m;M++) {
        int k,d;
        scanf("%d%d",&k,&d);
        order(k,d);
        for (int i=0;i<n;i++) {
            int where = min(i,k-1);
            int num = 0;
            for (int j=19;j>=0;j--) {
                if (jump[j][where]==0) continue;
                where = jump[j][where]-1;
                num+=1<<j;
            }
            num+=1;
            if (num>n-k-max(0,i-k+1)+1) {
                num = n-k-max(0,i-k+1)+1;
                where = n-k+go(min(i,k-1),num);
            } else where = max(0,i-k+1)+num-1;
            S2[where] = S[i];
        }
        printf("%s\n",S2);
        swap(S,S2);
    }

    return 0;
}