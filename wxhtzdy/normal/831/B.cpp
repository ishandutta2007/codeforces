#include <bits/stdc++.h>
using namespace std;
const int N=26;
char a[N],b[N],s[1050];
map<char,char> c;
int main(){
    scanf("%s %s %s",&a,&b,&s);
    int n=(int)strlen(s);
    for(int i=0;i<N;i++)c[a[i]]=b[i];
    for(int i=0;i<n;i++){
        if(s[i]>='0'&&s[i]<='9'){
            printf("%c",s[i]);
            continue;
        }
        if(s[i]<'a'){
            printf("%c",(char)(c[(char)(s[i]+'a'-'A')]-('a'-'A')));
        }else{
            printf("%c",c[s[i]]);
        }
    }
    return 0;
}