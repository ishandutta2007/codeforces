#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
int x[200000],n,A[200000],B[200000],ans[200000][2],len,C[200000];
int check(int k){
    int win1=0,win2=0,R=0;
    while (R!=n){
        int l=R+1,r=n+1,ans=-1;
        while (l<r){
            int mid=l+r>>1;
            if (A[mid]-A[R]>=k||B[mid]-B[R]>=k){
                ans=mid; r=mid;
            } else l=mid+1;
        }
        if (ans==-1) return -1;
        if (x[ans]==1) win1++; else win2++; R=ans;
    }
    if (win1==win2) return -1;
    if (win1>win2){
        if (x[n]==2) return -1; else return win1;
    } else if (x[n]==1) return -1; else return win2;
}
int compare(int k1,int k2){
    return ans[k1][0]<ans[k2][0]||(ans[k1][0]==ans[k2][0]&&ans[k1][1]<ans[k2][1]);
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&x[i]);
    for (int i=1;i<=n;i++) A[i]=A[i-1]+(x[i]==1);
    for (int i=1;i<=n;i++) B[i]=B[i-1]+(x[i]==2);
    for (int i=1;i<=n;i++){
        int k1=check(i); if (k1!=-1){len++; ans[len][0]=k1; ans[len][1]=i;}
    }
    cout<<len<<endl;
    for (int i=1;i<=len;i++) C[i]=i; sort(C+1,C+len+1,compare); 
    for (int i=1;i<=len;i++) printf("%d %d\n",ans[C[i]][0],ans[C[i]][1]);
    return 0;
}