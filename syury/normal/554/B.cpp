#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

int n;
vector<vector<char> >a;
int ans=0;

int main(){
    scanf("%d",&n);
    a.resize(n);
    for(int i=0;i<n;i++){
        a[i].resize(n);getc(stdin);
        for(int j=0;j<n;j++){
            a[i][j]=getc(stdin);
        }
    }
    for(int i=0;i<n;i++){
        int cnt=0;
        for(int j=0;j<n;j++){
            bool eq=true;
            for(int k=0;k<n;k++){
                if(a[i][k]!=a[j][k]){eq=false;break;}
            }
            if(eq){cnt++;}
        }
        ans=max(ans,cnt);
    }
    printf("%d",ans);
    return 0;
}