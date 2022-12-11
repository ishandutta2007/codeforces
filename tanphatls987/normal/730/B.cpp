#include <bits/stdc++.h>

using namespace std;

const int N=60;
int h[N],ans[2];
int main(){
    int test,n;
    char ch;
    cin>>test;
    while (test--){
        cin>>n;
        memset(h,0,sizeof(h));
        for(int i=2;i<=n;i+=2){
            printf("? %d %d\n",i-1,i);
            fflush(stdout);
            cin>>ch;
            if (ch=='<') h[i-1]=1;
            else h[i]=1;
        }

        for(int i=1;i>=0;i--){
            if (n&1) h[n]=i;
            ans[i]=1;
            while (h[ans[i]]!=i) ans[i]++;

            for(int j=ans[i]+1;j<=n;j++) if (h[j]==i){
                printf("? %d %d\n",j,ans[i]);
                fflush(stdout);
                cin>>ch;
                if (ch==(i?'<':'>')) ans[i]=j;
            }
        }
        printf("! %d %d\n",ans[1],ans[0]);
        fflush(stdout);
    }
}