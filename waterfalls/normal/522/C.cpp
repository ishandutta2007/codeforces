#include <cstdio>
#include <algorithm>


using namespace std;

int tests,m,k;
int a[100013];
int T[100013];
int R[100013];
int canBeOuts[100013];
int left[100013];
int needToBeIt[100013];

int main() {
    scanf("%d",&tests);
    for (int t=0;t<tests;t++) {
        scanf("%d%d",&m,&k);
        m-=1;
        for (int i=0;i<k;i++) scanf("%d",&a[i]);
        for (int i=0;i<m;i++) scanf("%d%d",&T[i],&R[i]);
        for (int i=0;i<m;i++) T[i]-=1;
        int firstOut = m;
        for (int i=0;i<m;i++) if (R[i]==1) firstOut = min(firstOut,i);
        for (int i=0;i<k;i++) canBeOuts[i] = 1;
        for (int i=firstOut;i<m;i++) if (T[i]!=-1) canBeOuts[T[i]] = 0;
        for (int i=0;i<k;i++) left[i] = a[i];
        for (int i=0;i<m;i++) if (T[i]!=-1) left[T[i]]-=1;
        int qsBefore = 0;
        for (int i=0;i<firstOut;i++) if (T[i]==-1) qsBefore+=1;
        for (int i=0;i<k;i++) needToBeIt[i] = -1;
        for (int i=0;i<k;i++) if (canBeOuts[i] && qsBefore>=left[i]) needToBeIt[i] = left[i];
        int minNeed = -1;
        for (int i=0;i<k;i++) if (needToBeIt[i]!=-1 && (minNeed==-1 || needToBeIt[i]<needToBeIt[minNeed])) minNeed = i;
        int qsTotal = 0;
        for (int i=0;i<m;i++) if (T[i]==-1) qsTotal+=1;
        if (firstOut==m) {
            minNeed = 100012;
            needToBeIt[minNeed] = 0;
        }
        for (int i=0;i<k;i++) {
            if (i!=minNeed && (qsTotal-needToBeIt[minNeed]>=left[i] || needToBeIt[i]!=-1)) printf("Y");
            else if (i==minNeed) printf("Y");
            else printf("N");
        }
        printf("\n");
    }

    return 0;
}