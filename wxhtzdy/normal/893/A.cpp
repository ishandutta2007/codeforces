#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;scanf("%i",&n);
    int f=1,s=2;
    bool ok=1;
    for(int i=0,a;i<n;i++){
        scanf("%i",&a);
        if(a!=f&&a!=s)ok=0;
        if(a==f){
            for(int c:{1,2,3}){
                if(f!=c&&s!=c){
                    s=c;
                    break;
                }
            }
        }else{
            for(int c:{1,2,3}){
                if(f!=c&&s!=c){
                    f=c;
                    break;
                }
            }
        }
    }
    if(ok)printf("YES");
    else printf("NO");
    return 0;
}