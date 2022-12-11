#include <bits/stdc++.h>

using namespace std;

const string wowel="AEIOUY";


const int N=5e2+10;

int n,n1,a[N],fa[N];
int ans[N][2];

void solve(){
    int nans=0,des=0;
    int en=1;
    for(int i=1;i<=n1;i++){
        int sum=0;
        int st=en;
        while (en<=n&&sum<fa[i]) sum+=a[en++];
        if (sum!=fa[i]){
            printf("NO");
            return;
        }
        if (en-st==1) continue;
        int val=*max_element(a+st,a+en);
        int use=-1;
        for(int j=st;j<en;j++) if (a[j]==val){
            if (j>st&&a[j]>a[j-1]) use=j;
            if (j<en-1&&a[j]>a[j+1]) use=j;
        }
        if (use==-1){
            printf("NO");
            return;
        }
//        cout<<i<<" "<<use<<" "<<st<<" "<<en<<'\n';
        if (use>st&&a[use]>a[use-1]){
            for(int j=1;j<=use-st;j++){
                ++nans;
                ans[nans][0]=use-des,ans[nans][1]=-1;
                des++;
            }
            for(int j=1;j<en-use;j++){
                ++nans;
                ans[nans][0]=use-des,ans[nans][1]=1;
            }
            des+=en-use-1;
        }else{
            for(int j=1;j<en-use;j++){
                ++nans;
                ans[nans][0]=use-des,ans[nans][1]=1;
            }
            for(int j=1;j<=use-st;j++){
                ++nans;
                ans[nans][0]=use-des,ans[nans][1]=-1;
                des++;
            }
            des+=en-use-1;
        }
    }
    if (en!=n+1){
        printf("NO");
        return;
    }
    printf("YES\n");
    for(int i=1;i<=nans;i++) printf("%d %c\n",ans[i][0],(ans[i][1]==-1?'L':'R'));
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",a+i);
    scanf("%d",&n1);
    for(int i=1;i<=n1;i++) scanf("%d",fa+i);
    solve();
}