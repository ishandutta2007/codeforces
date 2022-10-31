#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    int gAlone = 0;
    int rAlone = 0;
    vector<int> diffs;
    char row[113];
    for (int i=0;i<n;i++) {
        scanf(" %s",&row);
        int g = -1;
        int r = -1;
        bool flag = false;
        for (int j=0;j<m;j++) {
            if (row[j]=='R') {
                if (r!=-1) {
                    if (m>2) rAlone+=1;
                    flag = true;
                } else r = j;
            } else if (row[j]=='G') {
                if (g!=-1) {
                    if (m>2) gAlone+=1;
                    flag = true;
                } else g = j;
            }
        }
        if (flag) continue;
        if (g==-1 && r==-1) continue;
        if (g==-1 && m>1) rAlone+=1;
        else if (r==-1 && m>1) gAlone+=1;
        else diffs.push_back(abs(r-g)-1);
    }
    if (gAlone==0 && diffs.size()==0) printf("Second\n");
    else if (rAlone==0 && diffs.size()==0) printf("First\n");
    else if (gAlone>0 && rAlone>0) printf("Draw\n");
    else if (gAlone>0) printf("First\n");
    else if (rAlone>0) printf("Second\n");
    else {
        bool flag = true;
        for (int i=0;i<10;i++) {
            int sum = 0;
            for (int j=0;j<diffs.size();j++) sum+=diffs[j]%2;
            if (sum%(k+1)!=0) {
                printf("First\n");
                flag = false;
                break;
            }
            for (int j=0;j<diffs.size();j++) diffs[j] = diffs[j]>>1;
        }
        if (flag) printf("Second\n");
    }

    return 0;
}