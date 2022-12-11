#include<bits/stdc++.h>
using namespace std;
int n;
char s[200][200];
bool check(int x,int y){
    return s[x][y]=='t'&&s[x+1][y+1]=='h'&&s[x+2][y+2]=='e'&&s[x+3][y+3]=='s'&&s[x+4][y+4]=='e'&&s[x+5][y+5]=='u'&&s[x+6][y+6]=='s';
}
int main(){
    scanf("%d\n",&n);
    for(int i=1;i<=n;i++){
        for(int o=1;o<=n;o++)s[i][o]=getchar();
        getchar();
    }
    for(int i=1;i+7-1<=n;i++){
        for(int o=1;o+7-1<=n;o++){
            if(check(i,o))return puts("YES"),0;
        }
    }
    puts("NO");
    return  0;
}
// theseus Minotaur