#include<iostream>
using namespace std;
int main(){
    int n,i,a[222222],flag[2];
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    scanf("%d",&a[i]);
    flag[0]=0;
    flag[1]=0;
    for(i=n;i>0;i--){
        flag[a[i]]++;
        if(flag[0]>0&&flag[1]>0){
            cout<<i<<endl;
            return 0;
        }
    }
}