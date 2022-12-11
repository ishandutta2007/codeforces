#include <bits/stdc++.h>

using namespace std;

const int N=1e3+10;
const string dict="aeiouy";
int n,a[N];
char s[N];

bool wowel(char ch){
    for(int i=0;i<dict.length();i++) if (ch==dict[i]) return 1;
    return 0;
}
int main(){
    scanf("%d\n",&n);
//    cout<<n<<'\n';
    for(int i=1;i<=n;i++) scanf("%d ",a+i);
    scanf("\n");
//    for(int i=1;i<=n;i++) cout<<a[i]<<" ";
//    scanf("\n");
    for(int phase=1;phase<=n;phase++){
        //fflush(stdin);
        gets(s);
        //printf("%s\n",s);
        int n1=strlen(s),sum=0;
        for(int i=0;i<n1;i++) sum+=wowel(s[i]);
        if (sum!=a[phase]){
            printf("NO");
            return 0;
        }
//        cout<<phase<<'\n';
    }
    printf("YES");
}