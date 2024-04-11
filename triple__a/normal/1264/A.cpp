#include<bits/stdc++.h>
using namespace std;
 
const int maxn=2000007;
int t,n,cnt;
int a[maxn],b[maxn];
int main(){
    scanf("%d",&t);
    while (t--){
        cnt=0;
        scanf("%d",&n);
        for (int i=1;i<=n;++i){
            scanf("%d",&a[i]);
        }
        int i=1;
        while (i<=n){
            int l=i;
            while (i<n&&a[i]==a[i+1]) i++;
            b[++cnt]=i-l+1;
            i++;
        }
        i=2;
        int j=0,sum=b[1];
        int s[2]={0,0};
        while (i<=cnt){
            s[j]+=b[i];
            sum+=b[i];
            if (sum>n/2) break;
            if (!j&&s[j]>b[1]) j=1;
            i++;
        }
        if (s[1]-b[i]<=b[1]){
            printf("0 0 0\n");
        }
        else{
            printf("%d %d %d\n",b[1],s[0],s[1]-b[i]);
        }
    }
    return 0;
}