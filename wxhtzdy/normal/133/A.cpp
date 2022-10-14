#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int main(){
    char a[150];
    scanf("%s",&a);
    for(int i=0;i<strlen(a);i++)if(a[i]=='H'||a[i]=='Q'||a[i]=='9'){printf("YES");return 0;}
    printf("NO");
}