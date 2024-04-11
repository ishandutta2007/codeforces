#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%i",&n);
    map<string,int> m;
    for(int i=0;i<n;i++){
        char a[100];
        scanf("%s",&a);
        if(m[(string)a]==0)printf("NO\n");
        else printf("YES\n");
        m[(string)a]++;
    }
}