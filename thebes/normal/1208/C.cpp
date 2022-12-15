#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<int> vi;
typedef vector<ll> vl;

#define pb push_back

const int MN = 2005;
int arr[MN][MN], i, j, n;

int main(){
    scanf("%d",&n);
    int k = n/2;
    for(i=0;i<k;i++){
        for(j=0;j<k;j++){
            int f = 4*(i*k+j);
            arr[i][j]=f;
            arr[i][j+k]=f+1;
            arr[i+k][j]=f+2;
            arr[i+k][j+k]=f+3;
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            printf("%d ",arr[i][j]);
        printf("\n");
    }
    return 0;
}