#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<map>
#define maxn 1000005
using namespace std;
int n;
int line[maxn];
map<int,int> save;
int main(){
    /*freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);*/
    scanf("%d",&n);
    if(n<=2){
        printf("0");
        return 0;
    }
    for(int i=0;i<n;i++)scanf("%d",&line[i]);
    sort(line,line+n);
    int now=-1;
    for(int i=0;i<n;i++){
        int cnt=0;
        now=line[i];
        while(i<n&&line[i]==now)i++,cnt++;
        i--;
        save[now]=cnt;
    }
    long long int ans=save[line[0]];
    if(save[line[0]]>=3){
        printf("%I64d",ans*(ans-1)*(ans-2)/6);
    }
    else if(save[line[0]]==2){
        ans=save[line[2]];
        printf("%I64d",ans);
    }
    else if(save[line[0]]==1){
        if(save[line[1]]>=2){
            ans=save[line[1]];
            printf("%I64d",ans*(ans-1)/2);
        }
        else{
            ans=save[line[2]];
            printf("%I64d",ans);
        }
    }
    return 0;
}