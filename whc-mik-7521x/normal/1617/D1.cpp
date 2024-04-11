#include<bits/stdc++.h>
using namespace std;
const int N=2e4+10;
int t,n,a[N];
vector<int>v;
int main(){
    scanf("%d",&t);
    while(t--){
        v.clear();
        scanf("%d",&n);
        for(int i=0;i<n/3;i++){
            printf("? %d %d %d\n",i*3+1,i*3+2,i*3+3);
            fflush(stdout);
            scanf("%d",&a[i]);
        }
        int pos;
        for(pos=0;pos<n/3;pos++)if(a[pos]!=a[pos+1])break;
        int kk[4]={a[pos],0,0,a[pos+1]};
        printf("? %d %d %d\n",pos*3+2,pos*3+3,pos*3+4);
        fflush(stdout);
        scanf("%d",&kk[1]);
        printf("? %d %d %d\n",pos*3+3,pos*3+4,pos*3+5);
        fflush(stdout);
        scanf("%d",&kk[2]);
        int now[2];
        for(int i=0;i<3;i++)if(kk[i]!=kk[i+1]){now[kk[i]]=pos*3+1+i,now[kk[i+1]]=pos*3+1+i+3;break;}
        for(int i=pos*3+1;i<=pos*3+6;i++){
            if(i==now[0]||i==now[1])continue;
            printf("? %d %d %d\n",now[0],now[1],i);
            fflush(stdout);
            int x;scanf("%d",&x);
            if(x==0)v.push_back(i);
        }
        for(int i=0;i<n/3;i++){
            if(i==pos||i==pos+1)continue;
            int res1,res2;
            printf("? %d %d %d\n",now[1^a[i]],i*3+1,i*3+2);
            fflush(stdout);
            scanf("%d",&res1);
            printf("? %d %d %d\n",now[1^a[i]],i*3+2,i*3+3);
            fflush(stdout);
            scanf("%d",&res2);
            if(a[i]==0){
                if(res1==0){
                    v.push_back(i*3+1),v.push_back(i*3+2);
                    if(res2==0)v.push_back(i*3+3);
                }
                else{
                    if(res2==0)v.push_back(i*3+2),v.push_back(i*3+3);
                    else v.push_back(i*3+1),v.push_back(i*3+3);
                }
            }
            else{
                if(res1==1){
                    if(res2==0)v.push_back(i*3+3);
                }
                else{
                    if(res2==1)v.push_back(i*3+1);
                    else v.push_back(i*3+2);
                }
            }
        }
        v.push_back(now[0]);
        printf("! %d ",(int)v.size());
        for(int i=0;i<(int)v.size();i++)printf("%d ",v[i]);
        fflush(stdout);
        puts("");
    }
    return  0;
}