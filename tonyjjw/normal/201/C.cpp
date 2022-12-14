#include<stdio.h>
#include<algorithm>
#define MN 100000

using namespace std;

int N,A[MN],O[MN+1];
long long L[MN+1],R[MN+1],M[MN+1],ans;

bool cmp(int a,int b){
    return M[a]+R[a]>M[b]+R[b];
}

int main(){
//  freopen("input.txt","r",stdin);
    int i,j;
    scanf("%d",&N),--N;
    for(i=0;i<N;i++)scanf("%d",A+i);
    L[0]=0;
    M[0]=0;
    for(i=1;i<=N;i++){
        if(A[i-1]==1)   L[i]=0;
        else    L[i]=L[i-1]+(A[i-1]/2 * 2);
        M[i]=M[i-1]+(A[i-1]-(A[i-1]+1&1));
    }
    R[N]=0;
    for(i=N-1;i>=0;i--){
        if(A[i]==1) R[i]=0;
        else    R[i]=R[i+1]+(A[i]/2 * 2);
    }
    for(i=0;i<=N;i++)O[i]=i;
    sort(O,O+(N+1),cmp);
    for(i=j=0;i<=N;i++){
        while(j<=N && O[j]<i)++j;
        if(ans<R[O[j]]+M[O[j]]-M[i]+L[i])ans=R[O[j]]+M[O[j]]-M[i]+L[i];
    }
    printf("%lld",ans);
    return 0;
}