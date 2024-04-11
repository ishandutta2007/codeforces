#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m,k,t,a[N];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&m,&k);
        for(int i=1;i<=k;i++)scanf("%d",&a[i]);
        vector<long long>k1,k2;
        for(int i=1;i<=k;i++){
            k1.push_back(a[i]/n<2?-1:a[i]/n-2);
            k2.push_back(a[i]/m<2?-1:a[i]/m-2);
        }
        stable_sort(k1.begin(),k1.end());
        stable_sort(k2.begin(),k2.end());
        reverse(k1.begin(),k1.end());
        reverse(k2.begin(),k2.end());
        int pd=0;
        long long sum1=0,sum2=0;
        for(long long i:k1){
            if(i==-1)break;
            sum1+=2;
            sum2+=i;
            if(sum1<=m&&m<=sum2+sum1)pd=1;
        }
        sum1=sum2=0;
        for(long long i:k2){
            if(i==-1)break;
            sum1+=2;
            sum2+=i;
            if(sum1<=n&&n<=sum2+sum1)pd=1;
        }
        puts(pd?"Yes":"No");
    }
    return 0;
}