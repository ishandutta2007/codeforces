#include<cstdlib>
#include<cstdio>
using namespace std;
bool judge(int a,int b){
    int k1=a%10,k2=a/10;
    int d1=b%10,d2=b/10;
    if(k1==d2&&k2==d1)return true;
    return false;
}
int main(){
    /*freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);*/
    int h,m;
    char ch;
    scanf("%d%c%d",&h,&ch,&m);
    int ans=0;
    while(true){
        if(judge(h,m)){
            printf("%d",ans);
            return 0;
        }
        m++;
        ans++;
        if(m==60){
            m=0;
            h++;
            if(h==24) h=0;
        }
    }
    return 0;
}