#include<stdio.h>
#include<algorithm>

using namespace std;

int N,M,N1,N2,ans,sum;
int atk[1000],def[1000],A[1000];
char str[5];

int main(){
//  freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
    int i,j,k;
    scanf("%d%d",&N,&M);
    for(i=0;i<N;i++){
        scanf("%s",str);
        if(*str=='A')scanf("%d",atk+N1++);
        else        scanf("%d",def+N2++);
    }
    for(i=0;i<M;i++)scanf("%d",A+i);
    sort(atk,atk+N1),sort(def,def+N2),sort(A,A+M);
    ans=0;
    for(i=0;i<M && i<N1;i++){
        if(A[M-1-i]<=atk[i])break;
        ans+=A[M-1-i]-atk[i];
    }
    sum=0;
    for(i=N2-1;i>=0;i--){
        j=upper_bound(A,A+M,def[i])-A;
        if(j==M)break;
        for(k=j;k<M;k++)A[k]=A[k+1];
        M--;
    }
    if(i>=0){
        printf("%d",ans);
        return 0;
    }
    for(i=0;i<M;i++)sum+=A[i];
    for(i=0;i<N1;i++)sum-=atk[i];
    for(i=N1-1;i>=0;i--){
        j=lower_bound(A,A+M,atk[i])-A;
        if(j==M)break;
        for(k=j;k<M;k++)A[k]=A[k+1];
        M--;
    }
    if(i>=0){
        printf("%d",ans);
        return 0;
    }
    if(ans<sum)ans=sum;
    printf("%d",ans);
    return 0;
}