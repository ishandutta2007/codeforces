#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int n;
int a[2010], b[2010];
int p, INF = 987654321;
int tra[10010][10];
int add[10010][10];
int con[10010];
int ron[800];
int pnum[10010];
vector<int> lis[5];
int D[2010][800][10];

int main() {
    int i, j, k;

    scanf("%d",&n);
    for (i=1;i<=n;i++) {
        scanf("%d%d",&a[i],&b[i]);
    }
    for (i=0;i<10000;i++) {
        vector<int> arr;
        int ti = i;
        for (j=0;j<4;j++){
            if (ti%10) pnum[i]++;
            arr.push_back(ti%10);
            ti/=10;
        }
        for (j=0;j<3;j++) if (arr[j]<arr[j+1]) break;
        if (j!=3) continue;
        for (j=1;j<10;j++) {
            vector<int> brr(arr.begin(),arr.end());
            for (k=0;k<4;k++) if (brr[k]<j) break;
            if (k==4) continue;
            for (int l=3;l>k;l--) brr[l]=brr[l-1];
            brr[k]=j;
            add[i][j] = brr[0]+brr[1]*10+brr[2]*100+brr[3]*1000;
        }
        ron[p] = i;
        con[i] = p; p++;
        for (j=0;j<10;j++) {
            int ti=i, tti=i, tt = 1;
            for (k=0;k<4;k++) {
                if (ti%10==j) tti-=tt*j;
                ti/=10;tt*=10;
            }
            vector<int> brr;
            ti = tti;
            for (k=0;k<4;k++) {
                brr.push_back(ti%10); ti/=10;
            }
            sort(brr.begin(),brr.end(),greater<int>());
            tra[i][j] = brr[0]+brr[1]*10+brr[2]*100+brr[3]*1000;
        }
        lis[pnum[i]].push_back(p-1);
    }
    for (i=n;i>=0;i--) {
        for (j=0;j<5;j++) {
            if (i==n&&j==0) continue;
            for (int &v:lis[j]) {
                for (k=1;k<10;k++) {
                    D[i][v][k] = INF;
                    int ti = ron[v];
                    for (int l=0;l<4;l++) {
                        if (ti%10==0) break;
                        D[i][v][k] = min(D[i][v][k],D[i][con[tra[ron[v]][ti%10]]][ti%10]+abs(ti%10-k));
                        ti/=10;
                    }
                    if (i!=n&&j!=4) {
                        D[i][v][k] = min(D[i][v][k],D[i+1][con[add[ron[v]][b[i+1]]]][a[i+1]]+abs(a[i+1]-k));
                    }
                }
            }
        }
    }
    printf("%d\n",D[0][0][1]+2*n);

    return 0;
}