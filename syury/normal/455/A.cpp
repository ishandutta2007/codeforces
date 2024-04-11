#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>

using namespace std;
typedef long long int lint;

lint n;
vector<lint>a;
vector<lint>ans,ansd;

int main(){
    scanf("%I64d",&n);
    a.resize(100001);ans.resize(100001);ansd.resize(100001);
    for(lint i=0;i<n;i++){
        lint tmp;
        scanf("%I64d",&tmp);
        a[tmp]++;
    }

    for(lint i=0;i<100001;i++){
            if(a[i]!=0){ansd[i]=ans[i-1]+i*a[i];}
            if(i>1){ans[i]=max(ans[i-1],ansd[i-1]);}
    }
    printf("%I64d",max(ans[100000],ansd[100000]));
    return 0;
}